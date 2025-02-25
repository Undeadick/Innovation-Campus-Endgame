#include "../inc/header.h"

void mx_restartLevel3(SDL_Renderer *renderer, GameState *state) {
    mx_playEndSound();
    SDL_ShowCursor(SDL_ENABLE);

    *state = LVL_3;

    createLvl3(renderer, state);
}
