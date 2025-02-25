#include "../inc/header.h"

void mx_handleThirdCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 620; 
    int y1 = 197;
    int x2 = x1 + 143; 
    int y2 = y1 + 43;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel2(renderer, state);
    }
}
