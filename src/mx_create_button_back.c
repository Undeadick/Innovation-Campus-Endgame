#include "../inc/header.h"

ButtonBack mx_createButtonBack(SDL_Renderer *renderer, int x, int y) {
    ButtonBack button;

    button.rect.x = x;
    button.rect.y = y;
    button.rect.w = BUTTON_BACK_WIDTH;
    button.rect.h = BUTTON_BACK_HEIGHT;

    button.texture = IMG_LoadTexture(renderer, "resource/img/button_back.png");
    if (!button.texture) {
        SDL_Log("Failed to load button texture: %s", IMG_GetError());
    }

    return button;
}
