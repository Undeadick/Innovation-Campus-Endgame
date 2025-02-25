#include "../inc/header.h"

static void handleStepCollision(Ball *ball, int x1, int y1, int x2, int y2) {
    if (ball->y + ball->radius >= y1 && 
        ball->y + ball->radius <= y2 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {

        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
}

void mx_handleSteps(Ball *ball) {
    handleStepCollision(ball, 1188, 320, 1248, 340);
    handleStepCollision(ball, 1088, 360, 1138, 380);
    handleStepCollision(ball, 978, 390, 1038, 410);
    handleStepCollision(ball, 878, 410, 928, 430);
}
