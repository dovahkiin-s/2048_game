#include <stdio.h>
#include "include/BoardPosition.h"

int main()
{
    BoardPosition b;
    b.set_value(5);
    int a = b.get_value();
    printf("a=%d", a);
}

