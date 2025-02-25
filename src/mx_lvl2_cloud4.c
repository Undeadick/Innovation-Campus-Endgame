#include "../inc/header.h"

void mx_handleFourthCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 598; 
    int y1 = 34;
    int x2 = x1 + 158; 
    int y2 = y1 + 34;
    
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        mx_restartLevel2(renderer, state);
    }
}
