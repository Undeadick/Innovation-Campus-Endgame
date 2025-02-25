#include "../inc/header.h"

static void handleFourthFloorPlatform1(Ball2 *ball) {
    SDL_Rect platform = {1012, 176, 129, 27};
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w) {
        if (ball->y + ball->radius > platform.y && 
            ball->y - ball->radius < platform.y + platform.h) {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            }
            else if (ball->y - ball->radius >= platform.y + platform.h) {
                ball->y = platform.y + platform.h + ball->radius;
                ball->vy = 0;
            } else {
                if (ball->x - ball->radius <= platform.x + platform.w && 
                    ball->x - ball->radius > platform.x + platform.w + ball->vx) {
                    ball->x = platform.x + platform.w + ball->radius;
                    ball->vx = 0;
                } else {
                    ball->vx = 0;
                }
            }
        }
    }
}

static void handleFourthFloorPlatform2(Ball2 *ball) {
    SDL_Rect platform = {893, 157, 108, 31};
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w) {
        if (ball->y + ball->radius > platform.y &&
             ball->y - ball->radius < platform.y + platform.h) {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            }
            else if (ball->y - ball->radius >= platform.y + platform.h) {
                ball->y = platform.y + platform.h + ball->radius;
                ball->vy = 0;
            } else {
                if (ball->x - ball->radius <= platform.x + platform.w && 
                    ball->x - ball->radius > platform.x + platform.w + ball->vx) {
                    ball->x = platform.x + platform.w + ball->radius;
                    ball->vx = 0;
                } else {
                    ball->vx = 0;
                }
            }
        }
    }
}

static void handleFourthFloorPlatform3(Ball2 *ball) {
    SDL_Rect platform = {547, 128, 336, 29};
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w) {
        if (ball->y + ball->radius > platform.y && 
            ball->y - ball->radius < platform.y + platform.h) {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            }
            else if (ball->y - ball->radius >= platform.y + platform.h) {
                ball->y = platform.y + platform.h + ball->radius;
                ball->vy = 0;
            } else {
                if (ball->x - ball->radius <= platform.x + platform.w && 
                    ball->x - ball->radius > platform.x + platform.w + ball->vx) {
                    ball->x = platform.x + platform.w + ball->radius;
                    ball->vx = 0;
                } else {
                    ball->vx = 0;
                }
            }
        }
    }
}

void mx_handlelvl2FourthFloor(Ball2 *ball) {
    handleFourthFloorPlatform1(ball);
    handleFourthFloorPlatform2(ball);
    handleFourthFloorPlatform3(ball);
}

