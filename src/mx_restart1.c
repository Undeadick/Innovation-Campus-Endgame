#include "../inc/header.h"

void mx_restartLevel1(SDL_Renderer *renderer, GameState *state) {
    mx_playEndSound();
    SDL_ShowCursor(SDL_ENABLE);

    *state = LVL_1;

    mx_createLvl1(renderer, state);
}
