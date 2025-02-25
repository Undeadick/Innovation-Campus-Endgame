#include "../inc/header.h" 

static void handleFirstGroundLvl3(Ball3 *ball) {
    SDL_Rect platform = {1, 121, 657, 34};
    if (ball->x + ball->radius > platform.x &&
        ball->x - ball->radius < platform.x + platform.w &&
        ball->y + ball->radius > platform.y && 
        ball->y - ball->radius < platform.y + platform.h) {
        if (ball->y + ball->radius - ball->vy <= platform.y) {
            ball->y = platform.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
        else if (ball->x + ball->radius - ball->vx <= platform.x) {
            ball->x = platform.x - ball->radius;
            ball->vx = 0;
        }
        else if (ball->x - ball->radius - ball->vx >= platform.x + platform.w) {
            ball->x = platform.x + platform.w + ball->radius;
            ball->vx = 0;
        }
        else {
            ball->vx = 0;
            ball->vy = 0;
        }
    }
}

static void handleSecondGroundLvl3(Ball3 *ball) {
    SDL_Rect platform = {849, 241, 153, 31};
    if (ball->x + ball->radius > platform.x &&
        ball->x - ball->radius < platform.x + platform.w &&
        ball->y + ball->radius > platform.y && 
        ball->y - ball->radius < platform.y + platform.h) {
        if (ball->y + ball->radius - ball->vy <= platform.y) {
            ball->y = platform.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
        else if (ball->x + ball->radius - ball->vx <= platform.x) {
            ball->x = platform.x - ball->radius;
            ball->vx = 0;
        }
        else if (ball->x - ball->radius - ball->vx >= platform.x + platform.w) {
            ball->x = platform.x + platform.w + ball->radius;
            ball->vx = 0;
        }
        else {
            ball->vx = 0;
            ball->vy = 0;
        }
    }
}

static void handleThirdGroundLvl3(Ball3 *ball) {
    SDL_Rect platform = {940, 415, 132, 25};
    if (ball->x + ball->radius > platform.x && 
        ball->x - ball->radius < platform.x + platform.w &&
        ball->y + ball->radius > platform.y && 
        ball->y - ball->radius < platform.y + platform.h) {
        if (ball->y + ball->radius - ball->vy <= platform.y) {
            ball->y = platform.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
        else if (ball->x + ball->radius - ball->vx <= platform.x) {
            ball->x = platform.x - ball->radius;
            ball->vx = 0;
        }
        else if (ball->x - ball->radius - ball->vx >= platform.x + platform.w) {
            ball->x = platform.x + platform.w + ball->radius;
            ball->vx = 0;
        }
        else {
            ball->vx = 0;
            ball->vy = 0;
        }
    }
}

void mx_handleAllGroundLvl3(Ball3 *ball) {
    handleFirstGroundLvl3(ball);
    handleSecondGroundLvl3(ball);
    handleThirdGroundLvl3(ball);
}
