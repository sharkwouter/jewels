#include "render.h"

#include <stdio.h>

void renderBoard(jewel (*jewels)[HEIGHT]) {
    unsigned char x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            printf("%d,", (int) jewels[x][y]);
        }
        printf("\n");
    }
}
