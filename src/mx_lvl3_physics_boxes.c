#include "../inc/header.h"

static void handleFirstBox(Ball3 *ball) {
    SDL_Rect box = {706, 199, 85, 12};
    if (ball->x + ball->radius > box.x && ball->x - ball->radius < box.x + box.w && 
        ball->y + ball->radius > box.y && ball->y - ball->radius < box.y + box.h) {
        
        if (ball->y + ball->radius - ball->vy <= box.y) {
            ball->y = box.y - ball->radius; ball->vy = 0; ball->onGround = true;
        } else if (ball->y - ball->radius - ball->vy >= box.y + box.h) {
            ball->y = box.y + box.h + ball->radius; ball->vy = 0;
        } else if (ball->x - ball->radius <= box.x + box.w && ball->x - ball->radius > box.x + box.w + ball->vx) {
            ball->x = box.x + box.w + ball->radius; ball->vx = 0;
        } else if (ball->x + ball->radius >= box.x && ball->x + ball->radius < box.x - ball->vx) {
            ball->x = box.x - ball->radius; ball->vx = 0;
        } else { ball->vx = 0; }
    }
}

static void handleSecondBox(Ball3 *ball) {
    SDL_Rect box = {1108, 307, 78, 18};
    if (ball->x + ball->radius > box.x && 
        ball->x - ball->radius < box.x + box.w && 
        ball->y + ball->radius > box.y && 
        ball->y - ball->radius < box.y + box.h) {
        
        if (ball->y + ball->radius - ball->vy <= box.y) {
            ball->y = box.y - ball->radius; ball->vy = 0; ball->onGround = true;
        } else if (ball->y - ball->radius - ball->vy >= box.y + box.h) {
            ball->y = box.y + box.h + ball->radius; ball->vy = 0;
        } else if (ball->x - ball->radius <= box.x + box.w && 
            ball->x - ball->radius > box.x + box.w + ball->vx) {
            ball->x = box.x + box.w + ball->radius; ball->vx = 0;
        } else if (ball->x + ball->radius >= box.x && 
            ball->x + ball->radius < box.x - ball->vx) {
            ball->x = box.x - ball->radius; ball->vx = 0;
        } else { ball->vx = 0; }
    }
}


void mx_handleBoxes(Ball3 *ball) {
    handleFirstBox(ball);
    handleSecondBox(ball);
}
