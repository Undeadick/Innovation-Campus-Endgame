#include "../inc/header.h"

static void handleGroundCollision(Ball *ball, int screenWidth) {
    int groundY = 85;
    int groundHeight = 39;
    int groundLength = 1103;
    int groundStartX = screenWidth - groundLength;
    if (ball->y + ball->radius >= groundY && 
        ball->y <= groundY + groundHeight &&
        ball->x - ball->radius >= groundStartX && 
        ball->x + ball->radius <= screenWidth) {
        ball->y = groundY - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    } else {
        ball->onGround = false;
    }
}

static void handleSecondFloor(Ball *ball) {
    int platformXStart = 38;
    int platformXEnd = 998;
    int platformY = 270;
    int platformHeight = 39;
    int platformBottomY = platformY + platformHeight;
    if (ball->x - ball->radius <= 40 && 
        ball->y + ball->radius >= 0 && 
        ball->y - ball->radius <= 269) {
        ball->x = 40 + ball->radius;
        ball->vx = 0;
    }
    if (ball->x - ball->radius < platformXStart && 
        ball->y + ball->radius >= platformY && 
        ball->y - ball->radius <= platformBottomY) {
        ball->x = platformXStart + ball->radius; 
        ball->vx = 0; 
    }
    if (ball->y + ball->radius >= platformY && 
        ball->y <= platformBottomY &&
        ball->x + ball->radius >= platformXStart && 
        ball->x - ball->radius <= platformXEnd) {
        ball->y = platformY - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) ball->vy = 0;
    }
}

static void handleThirdFloor(Ball *ball) {
    int x1 = 647, y1 = 500;
    int x2 = x1 + 197;
    int y2 = y1 + 220;
    if (ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y1 + 5 &&
        ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2) {
        ball->y = y1 - ball->radius;
        ball->onGround = true;
        if (ball->vy > 0) {
            ball->vy = 0;
        }
    }
    if (ball->x - ball->radius <= x1 + 5 && 
        ball->x - ball->radius >= x1 - 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x1 + ball->radius;
    }
    if (ball->x + ball->radius >= x2 - 5 && 
        ball->x + ball->radius <= x2 + 5 &&
        ball->y >= y1 && 
        ball->y - ball->radius <= y2) {
        ball->x = x2 - ball->radius;
    }
}


void mx_handleCollisionsGround(Ball *ball, int screenWidth) {
    handleGroundCollision(ball, screenWidth);
    handleSecondFloor(ball);
    handleThirdFloor(ball);
}
