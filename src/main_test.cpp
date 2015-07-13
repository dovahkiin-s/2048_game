#include <stdio.h>
#include "include/TestBoard.h"

int main()
{
    TestBoard test_board;
    
    int* outcome1 = new int[5];
    outcome1[0] = 13;
    outcome1[1] = 11;
    outcome1[2] = 8;
    outcome1[3] = 0;
    outcome1[4] = 2;
    bool success = test_board.test_create_array('c', 2, 'r', outcome1);
    if (success)
    {
        printf("Test1: Success\n");
    }
    else
    {
        printf("Test1: Failure\n");
    }
    delete []outcome1;
    
    int* outcome2 = new int[5];
    outcome2[0] = 0;
    outcome2[1] = 5;
    outcome2[2] = 7;
    outcome2[3] = 0;
    outcome2[4] = 0;
    success = test_board.test_create_array('c', 1, 'n', outcome2);
        if (success)
    {
        printf("Test2: Success\n");
    }
    else
    {
        printf("Test2: Failure\n");
    }
    delete []outcome2;
    
    int* outcome3 = new int[5];
    outcome3[0] = 12;
    outcome3[1] = 0;
    outcome3[2] = 11;
    outcome3[3] = 0;
    outcome3[4] = 10;
    success = test_board.test_create_array('l', 3, 'r', outcome3);
        if (success)
    {
        printf("Test3: Success\n");
    }
    else
    {
        printf("Test3: Failure\n");
    }
    delete []outcome3;
    
    int* outcome4 = new int[5];
    outcome4[0] = 0;
    outcome4[1] = 0;
    outcome4[2] = 13;
    outcome4[3] = 14;
    outcome4[4] = 15;
    success = test_board.test_create_array('l', 4, 'n', outcome4);
    if (success)
    {
        printf("Test4: Success\n");
    }
    else
    {
        printf("Test4: Failure\n");
    }
    delete []outcome4;
    
    
    // tests for tilt array
    BoardPosition** pos_array = new BoardPosition*[5];
    for (int i = 0; i < 5; ++i)
    {
        pos_array[i] = new BoardPosition();
    }
    
    pos_array[0]->set_value(2);
    pos_array[1]->set_value(0);
    pos_array[2]->set_value(2);
    pos_array[3]->set_value(0);
    pos_array[4]->set_value(2);
    
    int* outcome5 = new int[5];
    outcome5[0] = 0;
    outcome5[1] = 0;
    outcome5[2] = 0;
    outcome5[3] = 2;
    outcome5[4] = 4;
    success = test_board.test_tilt_array(pos_array, outcome5, 5, true);
    if (success)
    {
        printf("Test5: Success\n");
    }
    else
    {
        printf("Test5: Failure\n");
    }
    delete []outcome5;
    
    
    pos_array[0]->set_value(2);
    pos_array[1]->set_value(2);
    pos_array[2]->set_value(2);
    pos_array[3]->set_value(2);
    pos_array[4]->set_value(2);
    
    int* outcome6 = new int[5];
    outcome6[0] = 0;
    outcome6[1] = 0;
    outcome6[2] = 2;
    outcome6[3] = 4;
    outcome6[4] = 4;
    success = test_board.test_tilt_array(pos_array, outcome6, 5, true);
    if (success)
    {
        printf("Test6: Success\n");
    }
    else
    {
        printf("Test6: Failure\n");
    }
    delete []outcome6;
    
    pos_array[0]->set_value(2);
    pos_array[1]->set_value(2);
    pos_array[2]->set_value(2);
    pos_array[3]->set_value(0);
    pos_array[4]->set_value(0);
    
    int* outcome7 = new int[5];
    outcome7[0] = 0;
    outcome7[1] = 0;
    outcome7[2] = 0;
    outcome7[3] = 2;
    outcome7[4] = 4;
    success = test_board.test_tilt_array(pos_array, outcome7, 5, true);
    if (success)
    {
        printf("Test7: Success\n");
    }
    else
    {
        printf("Test7: Failure\n");
    }
    delete []outcome7;
    
    pos_array[0]->set_value(2);
    pos_array[1]->set_value(0);
    pos_array[2]->set_value(2);
    pos_array[3]->set_value(0);
    pos_array[4]->set_value(4);
    
    int* outcome8 = new int[5];
    outcome8[0] = 0;
    outcome8[1] = 0;
    outcome8[2] = 0;
    outcome8[3] = 4;
    outcome8[4] = 4;
    success = test_board.test_tilt_array(pos_array, outcome8, 5, true);
    if (success)
    {
        printf("Test8: Success\n");
    }
    else
    {
        printf("Test8: Failure\n");
    }
    delete []outcome8;
    
    pos_array[0]->set_value(2);
    pos_array[1]->set_value(2);
    pos_array[2]->set_value(2);
    pos_array[3]->set_value(2);
    pos_array[4]->set_value(2);
    
    int* outcome9 = new int[5];
    outcome9[0] = 0;
    outcome9[1] = 0;
    outcome9[2] = 2;
    outcome9[3] = 4;
    outcome9[4] = 4;
    success = test_board.test_tilt_array(pos_array, outcome9, 5, true);
    if (success)
    {
        printf("Test9: Success\n");
    }
    else
    {
        printf("Test9: Failure\n");
    }
    delete []outcome9;
    
    for (int i = 0; i < 5; ++i)
    {
        delete pos_array[i];
    }
    delete []pos_array;
    
}