#include "../inc/header.h"

static void handleLvl2StepOne(Ball2 *ball) {
    SDL_Rect ledge = {1085, 634, 40, 80};
    
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x + ball->radius >= ledge.x) {
                ball->x = ledge.x - ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

static void handleLvl2StepTwo(Ball2 *ball) {
    SDL_Rect ledge = {1135, 588, 43, 126};
    
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x + ball->radius >= ledge.x) {
                ball->x = ledge.x - ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}



static void handleLvl2StepThree(Ball2 *ball) {
    SDL_Rect ledge = {1185, 545, 42, 169};
    
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x + ball->radius >= ledge.x) {
                ball->x = ledge.x - ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}



static void handleLvl2StepFour(Ball2 *ball) {
    SDL_Rect ledge = {1238, 502, 40, 212};
    
    if (ball->x + ball->radius > ledge.x && 
        ball->x - ball->radius < ledge.x + ledge.w) {
        if (ball->y + ball->radius > ledge.y && 
            ball->y - ball->radius < ledge.y + ledge.h) {
            if (ball->y + ball->radius - ball->vy <= ledge.y) {
                ball->y = ledge.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            } else if (ball->x + ball->radius >= ledge.x) {
                ball->x = ledge.x - ball->radius;
                ball->vx = 0;
            } else {
                ball->vx = 0;
            }
        }
    }
}

void mx_handleLvl2AdditionalSteps(Ball2 *ball) {
    handleLvl2StepOne(ball);
    handleLvl2StepTwo(ball);
    handleLvl2StepThree(ball);
    handleLvl2StepFour(ball);
}
