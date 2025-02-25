#include "../inc/header.h"

static void handleFirstCloudLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 772; 
    int y1 = 25;
    int x2 = x1 + 144; 
    int y2 = y1 + 51;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel3(renderer, state);
    }
}

static void handleSecondCloudLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 443; 
    int y1 = 200;
    int x2 = x1 + 144; 
    int y2 = y1 + 51;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel3(renderer, state);
    }
}

static void handleThirdCloudLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 139; 
    int y1 = 257;
    int x2 = x1 + 144; 
    int y2 = y1 + 51;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 &&
        ball->y - ball->radius <= y2) {
        mx_restartLevel3(renderer, state);
    }
}

void mx_handleCloudsLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state) {
    handleFirstCloudLvl3(ball, renderer, state);
    handleSecondCloudLvl3(ball, renderer, state);
    handleThirdCloudLvl3(ball, renderer, state);
}
