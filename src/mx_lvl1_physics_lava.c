#include "../inc/header.h"

void mx_handleLava(Ball *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 850, y1 = 512;
    int width = 430, height = 143;
    int x2 = x1 + width, y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel1(renderer, state);
    }
}
