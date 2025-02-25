#include "../inc/header.h"

void mx_updateCursorBack(ButtonBack *button, int mouseX, int mouseY) {
    static bool cursorChanged = false;

    if (mouseX >= button->rect.x && 
        mouseX <= button->rect.x + button->rect.w &&
        mouseY >= button->rect.y && 
        mouseY <= button->rect.y + button->rect.h) {
        if (!cursorChanged) {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
            cursorChanged = true;
        }
    } else {
        if (cursorChanged) {
            SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
            cursorChanged = false;
        }
    }
}
