/* 
 * File:   BoardView.cpp
 * Author: lmachiso
 *
 * Created on July 12, 2015, 1:20 PM
 */

#include "include/BoardView.h"
#include <stdio.h>
#include <string.h>


BoardView::BoardView(const Board& board): m_board(board)
{
}


BoardView::~BoardView()
{
}


int BoardView::draw()
{
    int res = 0;
    for (int i = 0; i < m_board.get_size(); i++)
    {
        for (int j = 0; j < m_board.get_size(); j++)
        {
            // value cannot be larger than 4 characters + 2 extra spaces + "\0"
            char string_value[7];
            format_string_value(m_board.get_elem(i, j)->get_value(), string_value);
            if (strcmp(string_value, "") == 0)
            {
                // Error, something went wrong
                return -1;
            }
            printf("%s", string_value);
        }
        printf("\n");
    }
    printf("\n");
    printf("Score = %d", m_board.get_score());
    printf("\n");
    printf("\n");
    return res;
}


void BoardView::format_string_value(int value, char* string_value)
{
    // formats the value to be included in exactly 7 characters
    char tmp_string[20];
    sprintf(tmp_string, "%d", value);
    // any value cannot be larger than 2048, therefore cannot have more than 4 digits
    if (strlen(tmp_string) > 4)
    {
        strcpy(string_value, "");
    }
    else
    {
        while (strlen(tmp_string) < 6)
        {
            strcat(tmp_string, " ");
        }
    }
    strcpy(string_value, tmp_string);
}
