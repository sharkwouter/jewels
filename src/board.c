#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(jewel (*jewels)[HEIGHT]) {
    while(containsEmpty(jewels)) {
        dropJewels(jewels);
        // getMatches(jewels, NULL);
    }
}

int swap(jewel (*jewels)[HEIGHT], int x1, int y1, int x2, int y2) {
    jewel j1;
    unsigned char match_count;

    j1 = jewels[x1][y1];
    jewels[x1][y1] = jewels[x2][y2];
    jewels[x2][y2] = j1;
    
    match * matches = getMatches(jewels, &match_count);

    if(match_count == 0) {
        j1 = jewels[x1][y1];
        jewels[x1][y1] = jewels[x2][y2];
        jewels[x2][y2] = j1;
    }
    return match_count;
}

void dropJewels(jewel (*jewels)[HEIGHT]) {
    unsigned char x, y;
    for(x = 0; x < WIDTH; x++) {
        for(y = HEIGHT; y >= 0; y--) {
            if (jewels[x][y] != EMPTY)
                continue;
            
            if (y == 0) {
                jewels[x][y] = (jewel) (rand() % (NUMBER_OF_COLORS + 1));
            } else {
                jewels[x][y] = jewels[x][y-1];
                jewels[x][y-1] = EMPTY;
            }
        }
    }
}

match * getMatches(jewel (*jewels)[HEIGHT], unsigned char * count) {
    match * matches;
    unsigned char i, matches_found = 0;
    
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT - 2; y++) {
            if(jewels[x][y] == jewels[x][y+1] && jewels[x][y] == jewels[x][y+2]) {
                
                match * tmp = (match*) malloc((matches_found + 1) * sizeof(match));
                for(i = 0; i < matches_found; i++) {
                    tmp[i] = matches[i];
                }
                tmp[matches_found] = (match) {x, y, x, y+1, x, y+2};

                jewels[x][y] = EMPTY;
                jewels[x][y+1] = EMPTY;
                jewels[x][y+2] = EMPTY;

                free(matches);
                matches = tmp;
                matches_found++;
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH - 2; x++) {
            if(jewels[x][y] == jewels[x+1][y] && jewels[x][y] == jewels[x+2][y]) {
                
                match * tmp = (match*) malloc((matches_found + 1) * sizeof(match));
                for(i = 0; i < matches_found; i++) {
                    tmp[i] = matches[i];
                }
                tmp[matches_found] = (match) {x, y, x+1, y, x+2, y};

                jewels[x][y] = EMPTY;
                jewels[x+1][y] = EMPTY;
                jewels[x+2][y] = EMPTY;

                free(matches);
                matches = tmp;
                matches_found++;
            }
        }
    }

    return matches;
}

int containsEmpty(jewel (*jewels)[HEIGHT]) {
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