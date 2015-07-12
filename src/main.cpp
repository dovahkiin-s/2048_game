#include <stdio.h>
#include "include/Game.h"

int main()
{
    int board_size = 0;
    printf("Input game board size: ");
    scanf("%d", &board_size);
    if (board_size >= 4)
    {
        Game game(board_size);
        game.play();
    }
    else
    {
        printf("Invalid size! Exiting!\n");
    }
    printf("\n");
}

