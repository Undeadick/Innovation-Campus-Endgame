#include "../inc/header.h"

static void handleFirstSleepers(Ball2 *ball) {
    SDL_Rect platform = {347, 250, 44, 10};
    
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w) {
        if (ball->y + ball->radius > platform.y && 
            ball->y - ball->radius < platform.y + platform.h) {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else {
                ball->vx = 0;
            }
        }
    }
}

static void handleSecondSleepers(Ball2 *ball) {
    SDL_Rect platform = {470, 250, 44, 10};
    
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w) {
        if (ball->y + ball->radius > platform.y && 
            ball->y - ball->radius < platform.y + platform.h) {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else {
                ball->vx = 0;
            }
        }
    }
}

void mx_handleLvl2Sleepers(Ball2 *ball) {
    handleFirstSleepers(ball);
    handleSecondSleepers(ball);
}
