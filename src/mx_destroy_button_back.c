#include "../inc/header.h"

void mx_destroyButtonBack(ButtonBack *button) {
    if (button->texture) {
        SDL_DestroyTexture(button->texture);
        button->texture = NULL;
    }
}
