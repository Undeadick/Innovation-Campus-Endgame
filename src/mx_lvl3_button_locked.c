#include "../inc/header.h"

void mx_renderLockedLvl3Button(SDL_Renderer *renderer) {
    int x = 964;
    int y = 129;
    int w = BUTTON_LVL_WIDTH;
    int h = BUTTON_LVL_HEIGHT;

    SDL_Texture *lockedTexture = IMG_LoadTexture(renderer, "resource/img/locked_lvl.png");
    if (!lockedTexture) {
        SDL_Log("Failed to load locked lvl2 button texture: %s", IMG_GetError());
        return;
    }

    SDL_Rect lvl2ButtonRect = {x, y, w, h};
    SDL_RenderCopy(renderer, lockedTexture, NULL, &lvl2ButtonRect);
    SDL_DestroyTexture(lockedTexture);
}

