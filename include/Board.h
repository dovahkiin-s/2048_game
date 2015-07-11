/* 
 * File:   Board.h
 * Author: lmachiso
 *
 * Created on July 11, 2015, 1:10 PM
 */

#ifndef BOARD_H
#define	BOARD_H

#include "include/BoardPosition.h"

class Board
{
public:
    Board(int size = 4);
    ~Board();
    int create_random_tile();
    bool is_full() const;
    bool is_win() const;
    int tilt(char direction);
    static void swap_positions(BoardPosition* pos1, BoardPosition* pos2);
    static void merge_positions(BoardPosition* pos1, BoardPosition* pos2);
    
private:
    Board(const Board& new_board);
    Board& operator=(const Board& new_board);
    bool find_value(int value) const;
    void static tilt_array(BoardPosition* pos_array, int size);
    
    int m_size;
    BoardPosition** m_board; 
};

#endif	/* BOARD_H */

