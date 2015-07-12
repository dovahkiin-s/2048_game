#include <stdio.h>
#include "include/BoardPosition.h"
#include "include/BoardView.h"

void swap_positions(BoardPosition* pos1, BoardPosition* pos2)
{
    BoardPosition tmp_pos;
    tmp_pos = *pos1;
    *pos1 = *pos2;
    *pos2 = tmp_pos;
}


void merge_positions(BoardPosition* pos1, BoardPosition* pos2)
{
    //merges position 1 into position 2 and sets position 1 to 0
    pos2->set_value(pos2->get_value() + pos1->get_value());
    pos2->set_was_merged(true);
    pos1->set_value(0);
    pos1->set_was_merged(false);
}


void tilt_array(BoardPosition** pos_array, int size)
{
    // set all positions to not merged status
    for (int i = 0; i < size; ++i)
    {
        pos_array[i]->set_was_merged(false);
    }
    int j = 0;
    for (int i = size - 2; i >= 0; --i)
    {
        if (pos_array[i]->get_value() != 0)
        {
            // move tile until first occupied position is found
            j = i;
            while ((j < size - 1) && (pos_array[j + 1]->get_value() == 0))
            {
                swap_positions(pos_array[j], pos_array[j + 1]);
				++j;
            }

            // determine if the next position has same value and if so, merge tiles
            if ((j < size - 1) && 
                (pos_array[j]->get_value() == pos_array[j + 1]->get_value()) &&
                (!pos_array[j]->was_merged()))
            {
                merge_positions(pos_array[j], pos_array[j + 1]);
            }
        }
        // else do nothing with the current position
    }
    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", pos_array[i]->get_value());
    }
}

int main()
{
    Board board;

    BoardView view(const_cast<Board&>(board));
    view.draw();

    printf("\n");
    
    int a = 0;
    scanf("%d", &a);
}

