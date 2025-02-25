#include "../inc/header.h"

void mx_handlelvl2ThirdFloor(Ball2 *ball) {
    int left = 132;
    int right = 1280;
    int top = 302;
    int bottom = top + 26;
    if (ball->y + ball->radius >= top && 
        ball->y < bottom) {
        if (ball->y + ball->radius <= top + ball->vy && 
            ball->x + ball->radius > left && 
            ball->x < right) {
            ball->y = top - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
        else if (ball->y >= bottom - ball->vy && 
            ball->x + ball->radius > left && 
            ball->x < right) {
            ball->y = bottom;
            ball->vy = 0;
        }
    }
    if (ball->x + ball->radius > left && ball->x < right) {
        if (ball->x + ball->radius <= left + ball->vx &&
            ball->y + ball->radius > top && 
            ball->y < bottom) {
            ball->x = left - ball->radius;
            ball->vx = 0;
        }
    }
}
