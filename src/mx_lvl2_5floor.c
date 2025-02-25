#include "../inc/header.h"

void mx_handlelvl2FifthFloor(Ball2 *ball) {
    int x1 = 0, y1 = 128;
    int x2 = x1 + 314, y2 = y1 + 29;
    
    bool collidesX = ball->x + ball->radius > x1 && ball->x - ball->radius < x2;
    bool collidesY = ball->y + ball->radius > y1 && ball->y - ball->radius < y2;

    if (collidesX && collidesY) {
        if (ball->vy > 0 && ball->y + ball->radius - ball->vy <= y1) { 
            ball->y = y1 - ball->radius;
            ball->onGround = true;
            ball->vy = 0;
        } else if (ball->vx > 0 && ball->x + ball->radius > x2) { 
            ball->x = x2 - ball->radius;
            ball->vx = 0;
        }
    }
}

