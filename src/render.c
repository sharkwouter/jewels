#include "render.h"

#include <stdio.h>

void renderBoard(Jewel (*jewels)[HEIGHT], unsigned char x_pos, unsigned char y_pos) {
    unsigned char x, y;

    for (x = 0; x < WIDTH+1; x++) {
        printf("\e[40m \e[0m");
    }
    printf("\e[40m \e[0m\n");

    for (y = 0; y < HEIGHT; y++) {
        printf("\e[40m \e[0m");
        for (x = 0; x < WIDTH; x++) {
            char c = ' ';
            if (x == x_pos && y == x_pos) {
                c = 'x';
            }
            switch (jewels[x][y])
            {
            case RED:
                printf("\e[41m%c\e[0m", c);
                break;
            case ORANGE:
                printf("\e[47m%c\e[0m", c);
                break;
            case YELLOW:
                printf("\e[43m%c\e[0m", c);
                break;
            case GREEN:
                printf("\e[42m%c\e[0m", c);
                break;
            case BLUE:
                printf("\e[44m%c\e[0m", c);
                break;
            case INDIGO:
                printf("\e[46m%c\e[0m",c);
                break;
            case PURPLE:
                printf("\e[45m%c\e[0m", c);
                break;
            case NUMBER_OF_COLORS:
            case EMPTY:
                printf("\e[40m%c\e[0m", c);
                break;
            }
        }
        printf("\e[40m \e[0m\n");
    }

    for (x = 0; x < WIDTH + 1; x++) {
        printf("\e[40m \e[0m");
    }
    printf("\e[40m \e[0m\n");
}


void animateMatch(Match match) {}

void renderScore(unsigned int score) {
    printf("Score: %d\n", score);
}
