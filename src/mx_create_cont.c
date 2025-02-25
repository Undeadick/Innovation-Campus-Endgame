#include "../inc/header.h"

static SDL_Texture* loadButtonTexture(SDL_Renderer *renderer) {
    SDL_Surface *buttonSurface = IMG_Load("resource/img/finish_menu/continue_button.png");
    if (!buttonSurface) {
        SDL_Log("Failed to load continue button texture: %s", IMG_GetError());
        return NULL;
    }
    SDL_Texture *buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
    SDL_FreeSurface(buttonSurface);
    if (!buttonTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
    return buttonTexture;
}

static void renderButton(SDL_Renderer *renderer, SDL_Texture *buttonTexture) {
    SDL_Rect buttonRect = {481, 328, 318, 64};
    SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
    SDL_RenderPresent(renderer);
}

static void handleButtonEvents(SDL_Renderer *renderer, GameState *state) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *state = EXIT_GAME;
            break;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            int x = event.button.x;
            int y = event.button.y;
            SDL_Rect buttonRect = {481, 328, 318, 64};
            if (x >= buttonRect.x && x <= buttonRect.x + buttonRect.w &&
                y >= buttonRect.y && y <= buttonRect.y + buttonRect.h) {
                *state = LEVEL_SELECT;
                mx_openPlayImage(renderer, state);
            }
        }
    }
}

void mx_createContinueButton(SDL_Renderer *renderer, GameState *state) {
    SDL_Texture *buttonTexture = loadButtonTexture(renderer);
    if (!buttonTexture) return;

    renderButton(renderer, buttonTexture);
    handleButtonEvents(renderer, state);

    SDL_DestroyTexture(buttonTexture);
}
