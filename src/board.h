#ifndef BOARD_H
#define BOARD_H

#include "jewel.h"

#define WIDTH 8
#define HEIGHT 8

typedef struct {
    unsigned char x;
    unsigned char y;
} match;

void fill(jewel (*jewels)[HEIGHT]);

int swap(jewel (*jewels)[HEIGHT], int x1, int y1, int x2, int y2);

void dropJewels(jewel (*jewels)[HEIGHT]);

match * getMatches(jewel (*jewels)[HEIGHT], unsigned char * count);

int containsEmpty(jewel (*jewels)[HEIGHT]);

#endif // BOARD_H