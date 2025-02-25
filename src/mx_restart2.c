#include "../inc/header.h"

void mx_restartLevel2(SDL_Renderer *renderer, GameState *state) {
    mx_playEndSound();
    SDL_ShowCursor(SDL_ENABLE);

    *state = LVL_2;

    mx_createLvl2(renderer, state);
}
