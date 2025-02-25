#include "../inc/header.h"

void mx_handleSecondCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 0; 
    int y1 = 196;
    int x2 = x1 + 182;
    int y2 = y1 + 45; 
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel2(renderer, state);
    }
}
