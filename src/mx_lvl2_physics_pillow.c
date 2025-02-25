#include "../inc/header.h"

static void handlelvl2SecondPillow(Ball2 *ball) {
    SDL_Rect pillow = {288, 637, 55, 13};
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y + ball->radius > pillow.y && 
            ball->y < pillow.y + pillow.h) {
            ball->y = pillow.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
    }
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y > pillow.y && 
            ball->y - ball->radius < pillow.y + pillow.h) {
            ball->vx = 0;
        }
    }
}

static void handlelvl2ThirdPillow(Ball2 *ball) {
    SDL_Rect pillow = {410, 132, 52, 11};
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y + ball->radius > pillow.y && 
            ball->y < pillow.y + pillow.h) {
            ball->y = pillow.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
    }
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y > pillow.y &&
            ball->y - ball->radius < pillow.y + pillow.h) {
            ball->vx = 0;
        }
    }
}

static void handlelvl2FourthPillow(Ball2 *ball) {
    SDL_Rect pillow = {1221, 256, 51, 10};
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y + ball->radius > pillow.y && 
            ball->y < pillow.y + pillow.h) {
            ball->y = pillow.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
    }
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y > pillow.y && 
            ball->y - ball->radius < pillow.y + pillow.h) {
            ball->vx = 0;
        }
    }
}

static void handlelvl2FifthPillow(Ball2 *ball) {
    SDL_Rect pillow = {1160, 200, 42, 13};
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y + ball->radius > pillow.y && 
            ball->y < pillow.y + pillow.h) {
            ball->y = pillow.y - ball->radius;
            ball->vy = 0;
            ball->onGround = true;
        }
    }
    
    if (ball->x + ball->radius > pillow.x && 
        ball->x - ball->radius < pillow.x + pillow.w) {
        if (ball->y > pillow.y && 
            ball->y - ball->radius < pillow.y + pillow.h) {
            ball->vx = 0;
        }
    }
}

void mx_handleLvl2Pillows(Ball2 *ball) {
    handlelvl2SecondPillow(ball);
    handlelvl2ThirdPillow(ball);
    handlelvl2FourthPillow(ball);
    handlelvl2FifthPillow(ball);
}
