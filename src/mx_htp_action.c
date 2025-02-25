#include "../inc/header.h"

static void loadHtpImage(SDL_Renderer *renderer, SDL_Texture **texture) {
    SDL_Surface *htpImageSurface = IMG_Load("resource/img/htp_bg4.png");
    if (!htpImageSurface) {
        SDL_Log("Failed to load HTP image: %s", IMG_GetError());
        return;
    }
    *texture = SDL_CreateTextureFromSurface(renderer, htpImageSurface);
    SDL_FreeSurface(htpImageSurface);
    if (!*texture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
}

static void handleEvents(SDL_Event *event, int *running, GameState *state, ButtonBack *backButton) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT ||
            (event->type == SDL_KEYDOWN && 
                event->key.keysym.sym == SDLK_ESCAPE)) {
            *running = 0;
            *state = MAIN_MENU;
        }
        if (mx_handleButtonBackClick(backButton, event)) {
            mx_playClickSound();
            *state = MAIN_MENU;
            *running = 0;
        }
    }
}

static void renderScreen(SDL_Renderer *renderer, SDL_Texture *htpImageTexture, ButtonBack *backButton) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, htpImageTexture, NULL, NULL);
    mx_renderButtonBack(renderer, backButton);
    SDL_RenderPresent(renderer);
}

void mx_openHtpImage(SDL_Renderer *renderer, GameState *state) {
    SDL_Texture *htpImageTexture = NULL;
    loadHtpImage(renderer, &htpImageTexture);
    if (!htpImageTexture) return;
    *state = HTP_SCREEN;
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    ButtonBack backButton = mx_createButtonBack(renderer, 18, 21);
    SDL_Event event;
    int running = 1;
    while (running && *state == HTP_SCREEN) {
        handleEvents(&event, &running, state, &backButton);
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        mx_updateCursorBack(&backButton, mouseX, mouseY);

        renderScreen(renderer, htpImageTexture, &backButton);
    }
    mx_destroyButtonBack(&backButton);
    SDL_DestroyTexture(htpImageTexture);
}
