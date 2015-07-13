/* 
 * File:   TestBoard.h
 * Author: lmachiso
 *
 * Created on July 13, 2015, 8:28 PM
 */

#include "include/TestBoard.h"
#include <stdio.h>

TestBoard::TestBoard()
{   
    m_test_board = new Board(5);
    m_size = 5;
    
    // elements not mentioned here are set to 0
    m_test_board->get_elem(0, 0)->set_value(1);
    m_test_board->get_elem(0, 2)->set_value(2);
    m_test_board->get_elem(0, 4)->set_value(3);
    
    m_test_board->get_elem(1, 0)->set_value(4);
    m_test_board->get_elem(1, 1)->set_value(5);
    m_test_board->get_elem(1, 3)->set_value(6);
    
    m_test_board->get_elem(2, 1)->set_value(7);
    m_test_board->get_elem(2, 2)->set_value(8);
    m_test_board->get_elem(2, 3)->set_value(9);
    
    m_test_board->get_elem(3, 0)->set_value(10);
    m_test_board->get_elem(3, 2)->set_value(11);
    m_test_board->get_elem(3, 4)->set_value(12);
    
    m_test_board->get_elem(4, 2)->set_value(13);
    m_test_board->get_elem(4, 3)->set_value(14);
    m_test_board->get_elem(4, 4)->set_value(15);
}        


TestBoard::~TestBoard()
{
    delete m_test_board;
}


bool TestBoard::equal_arrays(BoardPosition** actual_array, int* expected_array, int size)
{
    int i = 0;
    while (i < size)
    {
        if (actual_array[i]->get_value() != expected_array[i])
        {
            return false;
        }
        ++i;
    }
    return true;
}


bool TestBoard::test_create_array(char component, int index, char direction, int* expected_array)
{
    bool success = false;
    BoardPosition** pos_array = new BoardPosition*[m_size];
    m_test_board->create_array(component, index, direction, pos_array, m_size);
    success = equal_arrays(pos_array, expected_array, m_size);
    delete []pos_array;
    return success;
}


bool TestBoard::test_tilt_array(BoardPosition** initial_array, int* expected_array, int size, bool expected_state)
{
    bool state_changed = false;
    m_test_board->tilt_array(initial_array, size, state_changed);
    if ((equal_arrays(initial_array, expected_array, size) == true) &&
       (state_changed == expected_state))
    {
        return true;
    }
    return false;
}