#include <stdio.h>
#include "include/Game.h"

int main()
{
    int board_size = 0;
    printf("Input game board size: ");
    scanf("%d", &board_size);
    Game game(board_size);
    game.play();
    printf("\n");
}

