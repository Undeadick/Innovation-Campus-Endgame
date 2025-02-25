#include "../inc/header.h"

static SDL_Texture *loadPlayImage(SDL_Renderer *renderer) {
    SDL_Surface *playImageSurface = IMG_Load("resource/img/blevels.png");
    if (!playImageSurface) {
        SDL_Log("Failed to load levels image: %s", IMG_GetError());
        return NULL;
    }

    SDL_Texture *playImageTexture = SDL_CreateTextureFromSurface(renderer, playImageSurface);
    SDL_FreeSurface(playImageSurface);
    if (!playImageTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
    return playImageTexture;
}

static void handleEvents(SDL_Renderer *renderer, GameState *state, ButtonBack *backButton, SDL_Event *event, int *running) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT || 
            (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)) {
            *running = 0;
            *state = MAIN_MENU;
        }
        if (mx_handleButtonBackClick(backButton, event)) {
            mx_playClickSound();
            *running = 0;
            *state = MAIN_MENU;
            break;
        }
        mx_createLvl1Button(renderer, event, state);
        if (*state == LVL_1) {
            *running = 0;
            break;
        }
        if (mx_isLevelUnlocked(2)) {
            mx_createLvl2Button(renderer, event, state);
        } else {
            mx_renderLockedLvl2Button(renderer);
        }
        if (*state == LVL_2) {
            *running = 0;
            break;
        }
        if (mx_isLevelUnlocked(3)) {
            mx_createLvl3Button(renderer, event, state);
        } else {
            mx_renderLockedLvl3Button(renderer);
        }
        if (*state == LVL_3) {
            *running = 0;
            break;
        }
    }
}

static void renderLevelButtons(SDL_Renderer *renderer, SDL_Event *event, GameState *state) {
    mx_createLvl1Button(renderer, event, state);
    if (mx_isLevelUnlocked(2)) {
        mx_createLvl2Button(renderer, event, state);
    } else {
        mx_renderLockedLvl2Button(renderer);
    }
    if (mx_isLevelUnlocked(3)) {
        mx_createLvl3Button(renderer, event, state);
    } else {
        mx_renderLockedLvl3Button(renderer);
    }
}

static void renderGame(SDL_Renderer *renderer, SDL_Texture *playImageTexture, ButtonBack *backButton, SDL_Event *event, GameState *state) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    SDL_Rect dstRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playImageTexture, NULL, &dstRect);
    mx_renderButtonBack(renderer, backButton);
    renderLevelButtons(renderer, event, state);
    SDL_RenderPresent(renderer);
}

void mx_openPlayImage(SDL_Renderer *renderer, GameState *state) {
    SDL_Texture *playImageTexture = loadPlayImage(renderer);
    if (!playImageTexture) return;

    *state = LEVEL_SELECT;
    ButtonBack backButton = mx_createButtonBack(renderer, 38, 618);
    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
    SDL_Event event;
    int running = 1;
    while (running && *state == LEVEL_SELECT) {
        handleEvents(renderer, state, &backButton, &event, &running);
        renderGame(renderer, playImageTexture, &backButton, &event, state);
    }
    SDL_DestroyTexture(playImageTexture);
    mx_destroyButtonBack(&backButton);
    if (*state == LVL_1) {
        mx_createLvl1(renderer, state);
    }
    if (*state == LVL_2) {
        mx_createLvl2(renderer, state);
    }
}
