#include "../inc/header.h"

void mx_createLvl2Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state) {
    int x = 565, y = 129, w = BUTTON_LVL_WIDTH, h = BUTTON_LVL_HEIGHT;
    SDL_Texture *lvl2Texture = IMG_LoadTexture(renderer, "resource/img/lvl2/lvl2_button.png");
    if (!lvl2Texture) { SDL_Log("Failed to load lvl2 button texture: %s", IMG_GetError()); return; }
    SDL_Rect lvl2ButtonRect = { x, y, w, h };
    SDL_RenderCopy(renderer, lvl2Texture, NULL, &lvl2ButtonRect);
    SDL_DestroyTexture(lvl2Texture);
    int mouseX, mouseY; SDL_GetMouseState(&mouseX, &mouseY);
    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    if (mouseX >= x && 
        mouseX <= x + w && 
        mouseY >= y && 
        mouseY <= y + h && 
        event->type == SDL_MOUSEBUTTONDOWN) {
        mx_playClickSound(); *state = LVL_2;
    }
}

