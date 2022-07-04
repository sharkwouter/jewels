#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "jewel.h"
#include "input.h"
#include "board.h"
#include "render.h"
#include "controller.h"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    srand(time(0));

    unsigned int score;
    unsigned char x, y;
    Input input;
    Jewel jewels[WIDTH][HEIGHT];

    fill(jewels);
    renderBoard(jewels, x, y);
    renderScore(score);

    int running = 1;
    while (running) {

    }

    return 0;
}
