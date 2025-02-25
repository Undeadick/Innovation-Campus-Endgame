#include "../inc/header.h"

bool mx_handleButtonBackClick(ButtonBack *button, SDL_Event *event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (mouseX >= button->rect.x && 
            mouseX <= button->rect.x + button->rect.w &&
            mouseY >= button->rect.y && 
            mouseY <= button->rect.y + button->rect.h) {
            return true;
        }
    }
    return false;
}
