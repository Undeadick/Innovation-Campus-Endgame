#include "../inc/header.h"

void mx_initBall(Ball *ball, float x, float y, float radius) {
    ball->x = x;
    ball->y = y;
    ball->radius = radius;
    ball->vx = 0;
    ball->vy = 0;
    ball->onGround = false;
}
