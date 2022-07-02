#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include "jewel.h"
#include "match.h"


void fill(jewel (*jewels)[HEIGHT]);

int swap(jewel (*jewels)[HEIGHT], int x1, int y1, int x2, int y2);

void dropJewels(jewel (*jewels)[HEIGHT]);

match * getMatches(jewel (*jewels)[HEIGHT], unsigned char * count);

int containsEmpty(jewel (*jewels)[HEIGHT]);

#endif // BOARD_H