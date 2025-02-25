#include "../inc/header.h"

static SDL_Texture* loadFinishTexture(SDL_Renderer *renderer) {
    SDL_Surface *finishSurface = IMG_Load("resource/img/finish_menu/finish_screen.png");
    if (!finishSurface) {
        SDL_Log("Failed to load finish screen image: %s", IMG_GetError());
        return NULL;
    }

    SDL_Texture *finishTexture = SDL_CreateTextureFromSurface(renderer, finishSurface);
    SDL_FreeSurface(finishSurface);
    if (!finishTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }
    return finishTexture;
}

static void renderFinishScreen(SDL_Renderer *renderer, SDL_Texture *finishTexture) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    SDL_Rect dstRect = {0, 0, windowWidth, windowHeight};

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, finishTexture, NULL, &dstRect);
}

static void renderTimeText(SDL_Renderer *renderer, float elapsedTime) {
    char timeText[50];
    sprintf(timeText, "Time: %.2f seconds", elapsedTime);
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    mx_renderBlackText(renderer, timeText, windowWidth / 2, windowHeight / 2 - 100);
}

static void handleFinishScreenEvents(SDL_Renderer *renderer, GameState *state) {
    SDL_Event event;
    bool isFinished = false;
    while (!isFinished) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                *state = EXIT_GAME;
                isFinished = true;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                int x = event.button.x;
                int y = event.button.y;
                SDL_Rect continueRect = {481, 328, 318, 64};
                if (x >= continueRect.x && x <= continueRect.x + continueRect.w &&
                    y >= continueRect.y && y <= continueRect.y + continueRect.h) {
                    *state = LEVEL_SELECT;
                    isFinished = true;
                    mx_openPlayImage(renderer, state);
                }
                SDL_Rect backToMenuRect = {481, 427, 318, 81};
                if (x >= backToMenuRect.x && x <= backToMenuRect.x + backToMenuRect.w &&
                    y >= backToMenuRect.y && y <= backToMenuRect.y + backToMenuRect.h) {
                    *state = MAIN_MENU;
                    isFinished = true;
                }
            }
        }
    }
}

void mx_createFinishScreen(SDL_Renderer *renderer, GameState *state, float elapsedTime) {
    static SDL_Cursor *arrowCursor = NULL;
    if (!arrowCursor) 
        arrowCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    SDL_Texture *finishTexture = loadFinishTexture(renderer);
    if (!finishTexture) return;

    renderFinishScreen(renderer, finishTexture);
    renderTimeText(renderer, elapsedTime);

    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(finishTexture);
    SDL_ShowCursor(SDL_ENABLE);
    SDL_SetCursor(arrowCursor);

    mx_createContinueButton(renderer, state);
    mx_createBackToMenuButton(renderer, state);

    handleFinishScreenEvents(renderer, state);
}
