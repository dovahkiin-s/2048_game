/* 
 * File:   Board.cpp
 * Author: lmachiso
 *
 * Created on July 11, 2015, 1:25 PM
 */

#include "include/Board.h"

Board::Board(int size): m_size(size)
{
    m_board = new BoardPosition*[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_board[i] = new BoardPosition[m_size];
    }

    m_board[0][1].set_value(5); 
    m_board[1][2].set_value(10);
    m_board[2][3].set_value(25);
    m_board[1][3].set_value(323);
}


Board::~Board()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete [] m_board[i];
    }
    delete [] m_board;
}


int Board::get_size() const
{
	return m_size;
}


BoardPosition* Board::get_elem(const int pos_x, const int pos_y) const
{
    return &m_board[pos_x][pos_y];
}


int Board::create_random_tile()
{
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
        while (j < 0)
        {
            if (m_board[i][j].get_value() == value)
            {
                return true;
            }
        }
        ++i;
    }
    return false;
}


int Board::tilt(char direction)
{
    int res = 0;
    BoardPosition* pos_array[4];
    switch (direction)
    {
    case 'w':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('c', i, 'r', pos_array, m_size);
            tilt_array(pos_array, m_size);
            reset_array(pos_array, m_size);
        }
        break;
    case 's':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('c', i, 'n', pos_array, m_size);
            tilt_array(pos_array, m_size);
            reset_array(pos_array, m_size);
        }
        break;
    case 'a':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('l', i, 'r', pos_array, m_size);
            tilt_array(pos_array, m_size);
            reset_array(pos_array, m_size);
        }
        break;
    case 'd':
        for (int i = 0; i < m_size; ++i)
        {
            create_array('l', i, 'n', pos_array, m_size);
            tilt_array(pos_array, m_size);
            reset_array(pos_array, m_size);
        }
        break;    
    default:
        return -1;
    }
    return res;
}


void Board::tilt_array(BoardPosition** pos_array, int size)
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
                ++j;
            }

            // determine if the next position has same value and if so, merge tiles
            if ((j < size - 1) && 
                (pos_array[j]->get_value() == pos_array[j + 1]->get_value()) &&
                (!pos_array[j]->was_merged()))
            {
                merge_positions(pos_array[j], pos_array[j + 1]);
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
            for (int i = size - 1; i < 0; --i)
            {
                pos_array[i] = &m_board[index][i];
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
            for (int i = size - 1; i < 0; --i)
            {
                pos_array[i] = &m_board[i][index];
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
