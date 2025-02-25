#include "../inc/header.h"

void mx_createLvl1Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state) {
    int x = 166;
    int y = 129;
    int w = BUTTON_LVL_WIDTH;
    int h = BUTTON_LVL_HEIGHT;
    SDL_Texture *lvl1Texture = IMG_LoadTexture(renderer, "resource/img/lvl1/lvl1_button.png");
    if (!lvl1Texture) {
        SDL_Log("Failed to load lvl1 button texture: %s", IMG_GetError());
        return;
    }
    SDL_Rect lvl1ButtonRect = {x, y, w, h};
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    SDL_RenderCopy(renderer, lvl1Texture, NULL, &lvl1ButtonRect);
    SDL_DestroyTexture(lvl1Texture);
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        if (mouseX >= x && 
            mouseX <= x + w &&
            mouseY >= y && 
            mouseY <= y + h) {
            mx_playClickSound();
            *state = LVL_1;
        }
    }
}
