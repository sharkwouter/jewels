#include <stdio.h>

#include "controller.h"

int pollInput(Input * input) {
    char scan;
    printf("Inputs:\nl,r,u,d - left, right, up, down\nc - confirm\nd - decline\nq - quit\n");
    scanf(" %c", &scan);

    switch (scan)
    {
    case 'l':
        *input = LEFT;
        break;
    case 'r':
        *input = RIGHT;
        break;
    case 'u':
        *input = UP;
        break;
    case 'd':
        *input = DOWN;
        break;
    case 'c':
        *input = CONFIRM;
        break;
    case 'd':
        *input = DECLINE;
        break;
    case 'q':
        *input = EXIT;
        break;
    default:
        return 0;
        break;
    }
}
