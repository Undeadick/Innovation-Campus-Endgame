#include "../inc/header.h"

void mx_handleCollisions3(Ball3 *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo) {
    if (ball->x - ball->radius < 0) {
        ball->x = ball->radius;
        ball->vx = 0;
    }
    if (ball->x + ball->radius > screenWidth) {
        ball->x = screenWidth - ball->radius;
        ball->vx = 0;
    }

    ball->onGround = false;

    mx_handleAllGroundLvl3(ball);
    mx_handleStepsLvl3(ball);
    mx_handleCloudsLvl3(ball, renderInfo->renderer, renderInfo->state);
    mx_handleBoxes(ball);

    if (!ball->onGround) {
        ball->onGround = false;
    }
    mx_handleCloudsLvl3(ball, renderInfo->renderer, renderInfo->state);
    mx_handleLavaLvl3(ball, renderInfo->renderer, renderInfo->state);
    mx_handleFinishLvl3(ball, renderInfo->renderer, renderInfo->state, timeInfo->levelTime);

    if (ball->y - ball->radius < 0) {
        ball->y = ball->radius;
        ball->vy = -ball->vy * 0.8f;
    }
}
