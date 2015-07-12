/* 
 * File:   Game.cpp
 * Author: lmachiso
 *
 * Created on July 12, 2015, 15:58 PM
 */

#include "include/Game.h"
#include <stdio.h>
#include <string.h>


Game::Game(int size): m_board(size), m_board_view(const_cast<Board&>(m_board))
{
}


Game::~Game()
{
}


void Game::play()
{
    char option[255] = { 0 };
    bool is_win = false;
    bool is_full = false;
    bool state_changed = true;
    while (strcmp(option, "x") != 0 && (!is_win) && (!is_full))
    {
        if (state_changed)
        {
            m_board.create_random_tile();
            state_changed = false;
        }
        m_board_view.draw();
        printf("Insert option (w, a, s, d, x): ");
        scanf("%s", reinterpret_cast<char*>(&option));
        if ((strcmp(option, "w") == 0) || (strcmp(option, "s") == 0) ||
            (strcmp(option, "a") == 0) || (strcmp(option, "d") == 0))
        {
            m_board.tilt(option[0], state_changed);
        }
        else if (strcmp(option, "x") != 0)
        {
            printf("Invalid option!\n");
        }
        is_win = m_board.is_win();
        if (is_win)
        {
            printf("The player has won!\n");
        }
        is_full = m_board.is_full();
        if (is_full)
        {
            printf("The player has lost!\n");
        }
    }
}