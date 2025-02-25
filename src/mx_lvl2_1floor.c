#include "../inc/header.h"

void mx_handlelvl2FirstFloor(Ball2 *ball, int screenWidth) {
    int groundY = 693;
    if (ball->y + ball->radius >= groundY) {
        ball->y = groundY - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    } else {
        ball->onGround = false;
    }
    if (ball->x - ball->radius <= 0) {
        ball->x = ball->radius;
        if (ball->vx < 0) {
            ball->vx = 0;
        }
    } else if (ball->x + ball->radius >= screenWidth) {
        ball->x = screenWidth - ball->radius;
        if (ball->vx > 0) {
            ball->vx = 0;
        }
    }
}
