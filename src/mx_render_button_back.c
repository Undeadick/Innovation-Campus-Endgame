#include "../inc/header.h"

void mx_renderButtonBack(SDL_Renderer *renderer, ButtonBack *button) {
    if (button->texture) {
        SDL_RenderCopy(renderer, button->texture, NULL, &button->rect);
    }
}

