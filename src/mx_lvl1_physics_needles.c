#include "../inc/header.h"

static void handleNeedlesOne(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 578, y1 = 230;
    int width = 176, height = 53;
    int x2 = x1 + width, y2 = y1 + height;

    if (ball->x + ball->radius >= x1 &&
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel1(renderer, state);
    }
}

static void handleNeedlesTwo(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 166, y1 = 532;
    int width = 474, height = 59;
    int x2 = x1 + width, y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel1(renderer, state);
    }
}

void mx_handleNeedles(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    handleNeedlesOne(ball, renderer, state);
    handleNeedlesTwo(ball, renderer, state);
}
