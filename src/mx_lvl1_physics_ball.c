#include "../inc/header.h"

void mx_handleCollisions(Ball *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo) {
    if (ball->x - ball->radius < 0) {
        ball->x = ball->radius;
        ball->vx = -ball->vx * 0.8f;
    }
    if (ball->x + ball->radius > screenWidth) {
        ball->x = screenWidth - ball->radius;
        ball->vx = -ball->vx * 0.8f;
    }

    mx_handleCollisionsGround(ball, screenWidth);
    mx_handleSteps(ball);
    mx_handlePillowSteps(ball);
    mx_handleCloudCollisions(ball, renderInfo->renderer, renderInfo->state);
    mx_handleNeedles(ball, renderInfo->renderer, renderInfo->state);
    mx_handleLava(ball, renderInfo->renderer, renderInfo->state);
    mx_handleFinish(ball, renderInfo->renderer, renderInfo->state, timeInfo->levelTime);

    if (ball->y - ball->radius < 0) {
        ball->y = ball->radius;
        ball->vy = -ball->vy * 0.8f;
    }
}
