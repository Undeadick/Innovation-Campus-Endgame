#include "../inc/header.h"

void mx_createLvl3Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state) {
    int x = 964, y = 129, w = BUTTON_LVL_WIDTH, h = BUTTON_LVL_HEIGHT;
    SDL_Texture *lvl3Texture = IMG_LoadTexture(renderer, "resource/img/lvl3/lvl3_button.png");
    if (!lvl3Texture) { SDL_Log("Failed to load lvl3 button texture: %s", IMG_GetError()); return; }
    SDL_Rect lvl3ButtonRect = { x, y, w, h };
    int mouseX, mouseY; SDL_GetMouseState(&mouseX, &mouseY);
    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    SDL_RenderCopy(renderer, lvl3Texture, NULL, &lvl3ButtonRect);
    SDL_DestroyTexture(lvl3Texture);
    if (mouseX >= x && 
        mouseX <= x + w && 
        mouseY >= y && 
        mouseY <= y + h && 
        event->type == SDL_MOUSEBUTTONDOWN) {
        mx_playClickSound(); *state = LVL_3; createLvl3(renderer, state);
    }
}

