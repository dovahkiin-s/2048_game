/* 
 * File:   Board.cpp
 * Author: lmachiso
 *
 * Created on July 11, 2015, 1:20 PM
 */

#include "include/Board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

Board::Board(int size): m_size(size)
{
    m_board = new BoardPosition*[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_board[i] = new BoardPosition[m_size];
    }

    // initialize random number generator
    srand(time(0));

    // allocate the free position array only once since allocation is expensive
    m_free_pos_array = new char*[m_size * m_size];
    for (int i = 0; i < m_size * m_size; i++)
    {
        // should be extended for larger boards
        m_free_pos_array[i] = new char[10];
    }

    m_score = 0;
}


Board::~Board()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete [] m_board[i];
    }
    delete [] m_board;

    // destroy the array of free positions
    for (int i = 0; i < m_size * m_size; i++)
    {
        delete m_free_pos_array[i];
    }
    delete []m_free_pos_array;
}


int Board::get_size() const
{
	return m_size;
}


int Board::get_score() const
{
	return m_score;
}


BoardPosition* Board::get_elem(const int pos_x, const int pos_y) const
{
    return &m_board[pos_x][pos_y];
}


int Board::create_random_tile()
{
    int size = 0;
    
    // get the free position from the matrix
    create_free_position_array(m_free_pos_array, size);
    
    // get the random position of the element
    int random_pos = rand() % size;

    // decode the indexes of the chosen position
    int i = 0;
    int j = 0;
    sscanf(m_free_pos_array[random_pos], "%d %d", &i, &j);

    // generate the new random value
    int random_value = get_random_value();
    m_board[i][j].set_value(random_value);

    // reset the array of free positions
    for (int i = 0; i < size; i++)
    {
        strcpy(m_free_pos_array[i], "");
    }

    return 0;
}


bool Board::is_full() const
{
    return !find_value(0);
}


bool Board::is_win() const
{
    return find_value(2048);
}


bool Board::find_value(int value) const
{
    int i = 0;
    int j = 0;
    while (i < m_size)
    {
        j = 0;
        while (j < m_size)
        {
            if (m_board[i][j].get_value() == value)
            {
                return true;
            }
            ++j;
        }
        ++i;
    }
    return false;
}


int Board::tilt(char direction, bool& state_changed)
{
    int res = 0;

    state_changed = false;

    BoardPosition** pos_array = new BoardPosition*[m_size];
    switch (direction)
    {
    case 'w':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('c', i, 'r', pos_array, m_size);
            tilt_array(pos_array, m_size, state_changed);
            reset_array(pos_array, m_size);
        }
        break;
    case 's':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('c', i, 'n', pos_array, m_size);
            tilt_array(pos_array, m_size, state_changed);
            reset_array(pos_array, m_size);
        }
        break;
    case 'a':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('l', i, 'r', pos_array, m_size);
            tilt_array(pos_array, m_size, state_changed);
            reset_array(pos_array, m_size);
        }
        break;
    case 'd':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('l', i, 'n', pos_array, m_size);
            tilt_array(pos_array, m_size, state_changed);
            reset_array(pos_array, m_size);
        }
        break;    
    default:
        return -1;
    }
    delete []pos_array;
    return res;
}


void Board::tilt_array(BoardPosition** pos_array, int size, bool& state_changed)
{
    // set all positions to not merged status
    for (int i = 0; i < size; ++i)
    {
        pos_array[i]->set_was_merged(false);
    }
    int j = 0;
    for (int i = size - 2; i >= 0; --i)
    {
        if (pos_array[i]->get_value() != 0)
        {
            // move tile until first occupied position is found
            j = i;
            while ((j < size - 1) && (pos_array[j + 1]->get_value() == 0))
            {
                swap_positions(pos_array[j], pos_array[j + 1]);
                state_changed = true;
                ++j;
            }

            // determine if the next position has same value and if so, merge tiles
            if ((j < size - 1) && 
                (pos_array[j]->get_value() == pos_array[j + 1]->get_value()) &&
                (!pos_array[j]->was_merged()))
            {
                merge_positions(pos_array[j], pos_array[j + 1]);
                m_score = m_score + pos_array[j + 1]->get_value();
                state_changed = true;
            }
        }
        // else do nothing with the current position
    }
}


void Board::swap_positions(BoardPosition* pos1, BoardPosition* pos2)
{
    BoardPosition tmp_pos;
    tmp_pos = *pos1;
    *pos1 = *pos2;
    *pos2 = tmp_pos;
}


void Board::merge_positions(BoardPosition* pos1, BoardPosition* pos2)
{
    //merges position 1 into position 2 and sets position 1 to 0
    pos2->set_value(pos2->get_value() + pos1->get_value());
    pos2->set_was_merged(true);
    pos1->set_value(0);
    pos1->set_was_merged(false);
}


int Board::create_array(char component, int index, char direction, BoardPosition** pos_array, int size)
{
    // creates an array from a line or a column in the matrix either in normal order or in reversed order
    if (component == 'l')
    {
        if (direction == 'n')
        {
            for (int i = 0; i < size; i++)
            {
                pos_array[i] = &m_board[index][i];
            }
        }
        else if (direction == 'r')
        {
            for (int i = 0; i < size; ++i)
            {
                pos_array[i] = &m_board[index][size - 1 - i];
            }
        }
        else
        {
            return -1;
        }
    }
    else if (component == 'c')
    {
        if (direction == 'n')
        {
            for (int i = 0; i < size; i++)
            {
                pos_array[i] = &m_board[i][index];
            }
        }
        else if (direction == 'r')
        {
            for (int i = 0; i < size; ++i)
            {
                pos_array[i] = &m_board[size - 1 - i][index];
            }
        }
        else
        {
            return -1;
        }    
    }
    else
    {
        return -1;
    }
    return 0;
}


void Board::reset_array(BoardPosition** pos_array, int size)
{
    // sets all the pointers in the array to be null
    // this is acceptable since the array is not supposed to have ownership of the objects to which it points to
    for (int i = 0; i < size; i++)
    {
        pos_array[i] = 0;
    }
}


void Board::create_free_position_array(char** free_pos_array, int& size) const
{
    int free_size = 0;
    for (int i = 0; i < m_size; ++i)
    {
        for (int j = 0; j < m_size; ++j)
        {
            if (m_board[i][j].get_value() == 0)
            {
                sprintf(free_pos_array[free_size], "%d %d", i, j);
                ++free_size;
            }
        }
    }
    size = free_size;
}


int Board::get_random_value()
{
    // get the value 2 with 90% probability and 4 with 10% probability
    int value = rand() % 10;
    if (value < 9)
    {
        return 2;
    }
    return 4;
}