#include "../inc/header.h"

void mx_handlelvl2SecondFloor(Ball2 *ball) {
    SDL_Rect floor = {0, 446, 1192, 27};
    int rightEdgeX = floor.x + floor.w;
    int rightEdgeTopY = floor.y;
    int rightEdgeBottomY = floor.y + floor.h;
    if (ball->x - ball->radius <= rightEdgeX && 
        ball->x - ball->radius > rightEdgeX - 7 &&
        ball->y + ball->radius > rightEdgeTopY && 
        ball->y - ball->radius < rightEdgeBottomY) {
        ball->x = rightEdgeX + ball->radius;
        ball->vx = 0;
        return;
    }
    if (ball->x + ball->radius > floor.x && 
        ball->x - ball->radius < floor.x + floor.w) {
        if (ball->y + ball->radius > floor.y && 
            ball->y - ball->radius < floor.y + floor.h) {
            if (ball->y + ball->radius - ball->vy <= floor.y) {
                ball->y = floor.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            }
            else if (ball->y - ball->radius < floor.y + floor.h && ball->vy < 0) {
                ball->y = floor.y + floor.h + ball->radius;
                ball->vy = 0;
            }
        }
    }
}
