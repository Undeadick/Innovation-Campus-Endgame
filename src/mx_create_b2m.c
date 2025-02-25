#include "../inc/header.h"

static SDL_Texture* loadBackToMenuButtonTexture(SDL_Renderer *renderer) {
    SDL_Surface *buttonSurface = IMG_Load("resource/img/finish_menu/button_back_to_menu.png");
    if (!buttonSurface) {
        SDL_Log("Failed to load back to menu button texture: %s", IMG_GetError());
        return NULL;
    }
    SDL_Texture *buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
    SDL_FreeSurface(buttonSurface);
    if (!buttonTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
    return buttonTexture;
}

static void renderBackToMenuButton(SDL_Renderer *renderer, SDL_Texture *buttonTexture) {
    SDL_Rect buttonRect = {481, 427, 318, 81};
    SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
    SDL_RenderPresent(renderer);
}

static void handleBackToMenuButtonEvents(GameState *state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = EXIT_GAME;
            break;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            int x = event.button.x;
            int y = event.button.y;
            SDL_Rect buttonRect = {481, 427, 318, 81};
            if (x >= buttonRect.x && x <= buttonRect.x + buttonRect.w &&
                y >= buttonRect.y && y <= buttonRect.y + buttonRect.h) {
                *state = MAIN_MENU;
            }
        }
    }
}

void mx_createBackToMenuButton(SDL_Renderer *renderer, GameState *state) {
    SDL_Texture *buttonTexture = loadBackToMenuButtonTexture(renderer);
    if (!buttonTexture) return;

    renderBackToMenuButton(renderer, buttonTexture);
    handleBackToMenuButtonEvents(state);

    SDL_DestroyTexture(buttonTexture);
}
