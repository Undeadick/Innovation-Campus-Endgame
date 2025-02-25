#include "../inc/header.h"

void mx_handleLavaLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state) {
    SDL_Rect lava = {155, 647, 1125, 73};

    if (ball->x + ball->radius > lava.x && 
        ball->x - ball->radius < lava.x + lava.w) {
        if (ball->y + ball->radius > lava.y && 
            ball->y - ball->radius < lava.y + lava.h) {
            mx_restartLevel3(renderer, state);
        }
    }
}
