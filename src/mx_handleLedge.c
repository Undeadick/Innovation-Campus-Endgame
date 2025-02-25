#include "../inc/header.h"

void mx_handleLedge(Ball2 *ball) {
    SDL_Rect ledge = {568, 661, 50, 32};
    
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x + ball->radius >= ledge.x) {
                ball->x = ledge.x - ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}
