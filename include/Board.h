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
    Board(int size);
    Board(const Board& board);
    ~Board();
    Board& operator=(const Board& board);
    int get_size() const;
    int get_score() const;
    BoardPosition* get_elem(const int pos_x, const int pos_y) const;
	int create_random_tile();
    bool is_full() const;
    bool is_win() const;
    int tilt(char direction, bool& state_changed);
    static void swap_positions(BoardPosition* pos1, BoardPosition* pos2);
    static void merge_positions(BoardPosition* pos1, BoardPosition* pos2);
    
private:
    bool find_value(int value) const;
    void tilt_array(BoardPosition** pos_array, int size, bool& state_changed);
    int create_array(char component, int index, char direction, BoardPosition** pos_array, int size);
    static void reset_array(BoardPosition** pos_array, int size);
    void create_free_position_array(char** free_pos_array, int& size) const;
    static int get_random_value();
    
    const int m_size;
    BoardPosition** m_board;
    char** m_free_pos_array;
    int m_score;
};

#endif	/* BOARD_H */

