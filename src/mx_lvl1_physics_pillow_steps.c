#include "../inc/header.h"

static void handlePillowStepOne(Ball *ball) {
    int x1 = 530, y1 = 494;
    int x2 = 610, y2 = y1 + 16; 
    if (ball->y + ball->radius >= y1 && 
        ball->y + ball->radius <= y1 + 5 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {
        
        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
    if (ball->x - ball->radius <= x1 && 
        ball->x > x1 - 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {   
        ball->x = x1 + ball->radius;
    }
    if (ball->x + ball->radius >= x2 && 
        ball->x < x2 + 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x2 - ball->radius;
    }
}

static void handlePillowStepTwo(Ball *ball) {
    int x1 = 403, y1 = 461;
    int x2 = 491, y2 = y1 + 16;
    if (ball->y + ball->radius >= y1 && 
        ball->y + ball->radius <= y1 + 5 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {
        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
    if (ball->x - ball->radius <= x1 &&
         ball->x > x1 - 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x1 + ball->radius;
    }
    if (ball->x + ball->radius >= x2 && 
        ball->x < x2 + 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x2 - ball->radius;
    }
}

static void handlePillowStepThree(Ball *ball) {
    int x1 = 273, y1 = 435;
    int x2 = 361, y2 = y1 + 16;
    if (ball->y + ball->radius >= y1 && 
        ball->y + ball->radius <= y1 + 5 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {
        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
    if (ball->x - ball->radius <= x1 && 
        ball->x > x1 - 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) { 
        ball->x = x1 + ball->radius;
    }
    if (ball->x + ball->radius >= x2 && 
        ball->x < x2 + 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x2 - ball->radius;
    }
}

static void handlePillowStepFour(Ball *ball) {
    int x1 = 621, y1 = 209;
    int x2 = x1 + 89, y2 = y1 + 17;
    if (ball->y + ball->radius >= y1 && 
        ball->y + ball->radius <= y1 + 5 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {
        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
    if (ball->x - ball->radius <= x1 && 
        ball->x > x1 - 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x1 + ball->radius;
    }
    if (ball->x + ball->radius >= x2 && 
        ball->x < x2 + 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x2 - ball->radius;
    }
}

void mx_handlePillowSteps(Ball *ball) {
    handlePillowStepOne(ball);
    handlePillowStepTwo(ball);
    handlePillowStepThree(ball);
    handlePillowStepFour(ball);
}
