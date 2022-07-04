#include <SDL.h>

#include "controller.h"

int pollInput(Input * input) {
    SDL_Event event;

    if(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            *input = EXIT;
            return 1;
        } else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym)
            {
            case SDLK_LEFT:
                *input = LEFT;
                break;
            case SDLK_RIGHT:
                *input = RIGHT;
                break;
            case SDLK_UP:
                *input = UP;
                break;
            case SDLK_DOWN:
                *input = DOWN;
                break;
            case SDLK_z:
                *input = CONFIRM;
                break;
            case SDLK_x:
                *input = DECLINE;
                break;
            case SDLK_ESCAPE:
                *input = EXIT;
                break;
            default:
                *input = NONE;
                break;
            }
            return 1;
        }
    }
    return 0;
}
