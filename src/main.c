#include <stdlib.h>

#include "jewel.h"
#include "board.h"
#include "render.h"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    unsigned char x, y;
    jewel jewels[WIDTH][HEIGHT];

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            jewels[x][y] = EMPTY;
        }
    }

    containsEmpty(jewels);

    fill(jewels);
    renderBoard(jewels);

    return 0;
}
