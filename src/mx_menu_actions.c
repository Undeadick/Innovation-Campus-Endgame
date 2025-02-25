#include "../inc/header.h"

static void handleMouseMotion(SDL_Renderer *renderer, int x, int y) {
    mx_updateCursor(renderer, x, y);
}

static void handleButtonClick(int x, int y, SDL_Renderer *renderer, SDL_Window *window, GameState *state) {
    SDL_Rect htpButton = {45, 585, 260, 80};
    SDL_Rect exitButton = {245, 265, 350, 105};
    SDL_Rect playButton = {245, 115, 350, 105};

    if (x >= htpButton.x && 
        x <= htpButton.x + htpButton.w &&
        y >= htpButton.y && 
        y <= htpButton.y + htpButton.h) {
        mx_playClickSound();
        mx_openHtpImage(renderer, state);
    }
    if (x >= exitButton.x && 
        x <= exitButton.x + exitButton.w &&
        y >= exitButton.y && 
        y <= exitButton.y + exitButton.h) {
        mx_playClickSound();
        mx_onExitPressed(window, renderer);
    }
    if (x >= playButton.x && 
        x <= playButton.x + playButton.w &&
        y >= playButton.y && 
        y <= playButton.y + playButton.h) {
        mx_playClickSound();
        mx_openPlayImage(renderer, state);
    }
}

void mx_handleButtonAction(SDL_Event *event, SDL_Renderer *renderer, SDL_Window *window, GameState *state) {
    int x; 
    int y;
    SDL_GetMouseState(&x, &y);

    if (event->type == SDL_MOUSEMOTION) {
        handleMouseMotion(renderer, x, y);
    } else if (event->type == SDL_QUIT) {
        *state = EXIT_GAME;
    } else if (event->type == SDL_MOUSEBUTTONDOWN) {
        handleButtonClick(x, y, renderer, window, state);
    }
}
