#include "../inc/header.h"

static void handleLvl2FirstStep(Ball2 *ball) {
    SDL_Rect ledge = {107, 410, 36, 36};
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x - ball->radius <= ledge.x + ledge.w) {
                ball->x = ledge.x + ledge.w + ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

static void handleLvl2SecondStep(Ball2 *ball) {
    SDL_Rect ledge = {71, 376, 36, 36};
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x - ball->radius <= ledge.x + ledge.w) {
                ball->x = ledge.x + ledge.w + ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

static void handleLvl2ThirdStep(Ball2 *ball) {
    SDL_Rect ledge = {35, 339, 36, 36};
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x - ball->radius <= ledge.x + ledge.w) {
                ball->x = ledge.x + ledge.w + ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

static void handleLvl2FourthStep(Ball2 *ball) {
    SDL_Rect ledge = {0, 303, 36, 36};
    if (ball->x + ball->radius > ledge.x && ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x - ball->radius <= ledge.x + ledge.w) {
                ball->x = ledge.x + ledge.w + ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

void mx_handleLvl2Steps(Ball2 *ball) {
    handleLvl2FirstStep(ball);
    handleLvl2SecondStep(ball);
    handleLvl2ThirdStep(ball);
    handleLvl2FourthStep(ball);
}
