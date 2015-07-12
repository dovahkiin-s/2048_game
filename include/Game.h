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
    //! Constructor
    /*!
    \param board_size - the size of the game board
    */
    Game(int board_size);
    
    //! Destructor
    /*!
    */
    ~Game();

    //! Main loop of the game - handles the game operations
    /*!
    \param board_size - the size of the game board
    */
    void play();

private:
    //! The board for the game
    Board m_board;

    //! The board viewer - displays the board
    /*!
    Can be later replaced with a proper graphical UI viewer
    */
    BoardView m_board_view;
};

#endif	/* GAME_H */