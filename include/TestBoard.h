/* 
 * File:   TestBoard.h
 * Author: lmachiso
 *
 * Created on July 13, 2015, 8:20 PM
 */

#ifndef TESTBOARD_H
#define	TESTBOARD_H

#include "include/Board.h"

class TestBoard
{
public:
    TestBoard();
    ~TestBoard();
    bool equal_arrays(BoardPosition** actual_array, int* expected_array, int size);
    bool test_create_array(char component, int index, char direction, int* expected_array);
    bool test_tilt_array(BoardPosition** initial_array, int* expected_array, int size, bool expected_state);

private:
    int m_size;
    Board *m_test_board;
};

#endif	/* TESTBOARD_H */

