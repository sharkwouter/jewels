#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include "jewel.h"
#include "match.h"


void fill(Jewel (*jewels)[HEIGHT]);

int swap(Jewel (*jewels)[HEIGHT], int x1, int y1, int x2, int y2);

void dropJewels(Jewel (*jewels)[HEIGHT]);

int getMatch(Jewel (*jewels)[HEIGHT], Match * match);


int containsEmpty(Jewel (*jewels)[HEIGHT]);

#endif // BOARD_H