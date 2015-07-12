/* 
 * File:   Game.h
 * Author: lmachiso
 *
 * Created on July 12, 2015, 15:54 PM
 */

#ifndef GAME_H
#define	GAME_H

#include "include/Board.h"
#include "include/BoardView.h"

class Game
{
public:
    Game(int board_size);
    ~Game();
    void play();

private:
    Board m_board;
    BoardView m_board_view;
};

#endif	/* GAME_H */