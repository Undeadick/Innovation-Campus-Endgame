#include "../inc/header.h"

static void handleFirstCloud(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 234, y1 = 157;
    int x2 = x1 + 151, y2 = y1 + 55;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel1(renderer, state);
    }
}

static void handleSecondCloud(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 1083, y1 = 123;
    int x2 = x1 + 180, y2 = y1 + 64;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel1(renderer, state);
    }
}

void mx_handleCloudCollisions(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    handleFirstCloud(ball, renderer, state);
    handleSecondCloud(ball, renderer, state);
}
