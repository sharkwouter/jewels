#include "board.h"
#include "render.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(Jewel (*jewels)[HEIGHT]) {
    unsigned char x, y, i, match_count;
    Match match;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            jewels[x][y] = (Jewel) (rand() % (NUMBER_OF_COLORS));
        }
    }
    
    while(getMatch(jewels, NULL)) {
        while(getMatch(jewels, &match)) {
            jewels[match.x1][match.y1] = EMPTY;
            jewels[match.x2][match.y2] = EMPTY;
            jewels[match.x3][match.y3] = EMPTY;
        }
        while(containsEmpty(jewels)) {
            dropJewels(jewels);
        }
    }
}

int swap(Jewel (*jewels)[HEIGHT], int x1, int y1, int x2, int y2) {
    Jewel j1;

    j1 = jewels[x1][y1];
    jewels[x1][y1] = jewels[x2][y2];
    jewels[x2][y2] = j1;
    
    if (!getMatch(jewels, NULL)) {
        j1 = jewels[x1][y1];
        jewels[x1][y1] = jewels[x2][y2];
        jewels[x2][y2] = j1;
        return 0;
    }
    return 1;
}

void dropJewels(Jewel (*jewels)[HEIGHT]) {
    unsigned char x, y;
    for(x = 0; x < WIDTH; x++) {
        for(y = (HEIGHT-1); y > 0; y--) {
            if (jewels[x][y] == EMPTY) {
                jewels[x][y] = jewels[x][y-1];
                jewels[x][y-1] = EMPTY;
            }
        }
        if (jewels[x][0] == EMPTY) {
            jewels[x][0] = (Jewel) (rand() % (NUMBER_OF_COLORS));
        }
    }
}

int getMatch(Jewel (*jewels)[HEIGHT], Match * match) {
    unsigned char x, y;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT - 2; y++) {
            if(jewels[x][y] != EMPTY && jewels[x][y] == jewels[x][y+1] && jewels[x][y] == jewels[x][y+2]) {
                if (match != NULL)
                    *match = (Match) {x, y, x, y+1, x, y+2};
                return 1;
            }
        }
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH - 2; x++) {
            if(jewels[x][y] != EMPTY && jewels[x][y] == jewels[x+1][y] && jewels[x][y] == jewels[x+2][y]) {
                if (match != NULL)
                    *match = (Match) {x, y, x+1, y, x+2, y};
                return 1;
            }
        }
    }

    return 0;
}

int containsEmpty(Jewel (*jewels)[HEIGHT]) {
    unsigned char x, y;

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if(jewels[x][y] == EMPTY) {
                return 1; 
            }
        }
    }
    return 0;
}