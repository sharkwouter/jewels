#include <SDL.h>
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

    unsigned int score, old_score, frame_delay = 200, start_frame, delta;
    unsigned char x, y, sx, sy, selected;
    Input input;
    Jewel jewels[WIDTH][HEIGHT];
    Match match;

    fill(jewels);
    initRenderer();

    int running = 1;
    while (running) {
        start_frame = SDL_GetTicks();
        renderBoard(jewels, x, y);
        if(!containsEmpty(jewels)) {
            if (isImpossible(jewels)) {
                renderFinale(score);
                running = 0;
                continue;
            }
        while(!pollInput(&input) || input == NONE) {
            
        }
        switch (input)
        {
        case LEFT:
            if (x > 0)
                x--;
            break;
        case RIGHT:
            if (x < WIDTH-1)
                x++;
            break;
        case UP:
            if (y > 0)
                y--;
            break;
        case DOWN:
            if (y < HEIGHT-1)
                y++;
            break;
        case CONFIRM:
            if(selected) {
                if(swap(jewels, sx, sy, x, y)) {
                    score += clearMatches(jewels);
                    renderScore(score);
                } else {
                    x = sx;
                    y = sy;
                }
                selected = 0;
            } else {
                selected = 1;
                sx = x;
                sy = y;
            }
            break;
        case DECLINE:
            selected = 0;
            break;
        case EXIT:
            running = 0;
            continue;
            break;
        default:
            break;
        }
        } else {
            animate();
            dropJewels(jewels);
            if(!containsEmpty(jewels)) {
                old_score = score;
                score += clearMatches(jewels);
                if (score != old_score) {
                    renderScore(score);
                }
            }
        }
    }

    return 0;
}
