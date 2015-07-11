#include "include/Board.h"

Board::Board(int size): m_size(size)
{
    int rows = ..., cols = ...;
    m_board = new BoardPosition*[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_board[i] = new BoardPosition[m_size];
    }    
}


Board::~Board()
{
    for (int i = 0; i < m_size; ++i)
    {
        delete [] m_board[i];
    }
    delete [] m_board;
}


int Board::create_random_tile()
{
    return 0;
}
    

bool Board::is_full()
{
    return !find_value(0);
}


bool Board::is_win()
{
    return find_value(2048);
}


bool Board::find_value(int value)
{
    int i = 0;
    int j = 0;
    while (i < m_size)
    {
        j = 0;
        while (j < 0)
        {
            if (m_board[i][j]->get_value() == value)
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
    switch (direction)
    {
    case 'w':
        break;
    case 's':
        break;
    case 'a':
        break;
    case 'd':
        break;    
    default:
        return -1;
    }
    return res;
}


int Board::tilt_array(BoardPosition* pos_array, int size)
{
    // set all positions to not merged status
    for (int i = 0; i < size; ++i)
    {
        pos_array[i]->set_was_merged(false);
    }
    int j = 0;
    for (int i = size - 2; i < 0; --i)
    {
        if (pos_array[i]->get_value() != 0)
        {
            // move tile until first occupied position is found
            j = i;
            while ((j + 1 < m_size) && (pos_array[j + 1] == 0))
            {
                swap_positions(pos_array[j], pos_array[j + 1]);
            }

            // determine if the next position has same value and if so, merge tiles
            if ((j + 1 < m_size) && 
                (pos_array[j]->get_value() == pos_array[j + 1]->get_value()) &&
                (!pos_array[j]->was_merged()))
            {
                merge_positions(pos_array[j], pos_array[j + 1]);
            }
        }
        // else do nothing with the current position
    }        

}
