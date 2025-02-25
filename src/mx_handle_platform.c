#include "../inc/header.h"

void mx_handlePlatform(Ball2 *ball) {
    SDL_Rect platform = {686, 604, 207, 18};
    
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
