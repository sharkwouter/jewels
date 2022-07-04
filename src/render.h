#ifndef RENDER_H
#define RENDER_H

#include "jewel.h"
#include "match.h"
#include "constants.h"

void initRenderer();

void closeRenderer();

void renderBoard(Jewel (*jewels)[HEIGHT], unsigned char x_pos, unsigned char y_pos);

void animate();

void renderScore(unsigned int score);

#endif // RENDER_H