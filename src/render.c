#include "render.h"

#include <SDL.h>

#define NAME "Jewels"
#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512
#define JEWEL_SIZE 64
#define MARGIN 4

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

void initRenderer() {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);

    window = SDL_CreateWindow(
        NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void closeRenderer() {

}

void renderBoard(Jewel (*jewels)[HEIGHT], unsigned char x_pos, unsigned char y_pos) {
    unsigned char x, y;
    unsigned short rx, ry;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    for(x = 0, rx = 0; x < WIDTH; x++, rx += JEWEL_SIZE) {
        for(y = 0, ry = 0; y < HEIGHT; y++, ry += JEWEL_SIZE) {
            SDL_Rect rect;
            rect.x = rx;
            rect.y = ry;
            rect.w = JEWEL_SIZE;
            rect.h = JEWEL_SIZE;
            if (x == x_pos && y == y_pos) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }

            switch (jewels[x][y])
            {
            case RED:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                break;
            case ORANGE:
                SDL_SetRenderDrawColor(renderer, 255, 127, 0, 255);
                break;
            case YELLOW:
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                break;
            case GREEN:
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                break;
            case BLUE:
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                break;
            case INDIGO:
                SDL_SetRenderDrawColor(renderer, 75, 0, 130, 255);
                break;
            case PURPLE:
                SDL_SetRenderDrawColor(renderer, 148, 0, 211, 255);
                break;
            default:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                break;
            }

            rect.x += MARGIN;
            rect.y += MARGIN;
            rect.w -= MARGIN<<1;
            rect.h -= MARGIN<<1;
            SDL_RenderFillRect(renderer, &rect);

        }
    }
    SDL_RenderPresent(renderer);
}


void animate() {
    SDL_Delay(300);
}

void renderScore(unsigned int score) {
    printf("Score: %d\n", score);
}

void renderFinale(unsigned int score) {
    printf("No more moves, game over!\nFinal score: %d\n", score);
}
