#include "../inc/header.h"

static void handleLevel2Floors(Ball2 *ball) {
    mx_handlelvl2SecondFloor(ball);
    mx_handlelvl2ThirdFloor(ball);
    mx_handlelvl2FourthFloor(ball);
    mx_handlelvl2FifthFloor(ball);
}

static void handleLevel2Objects(Ball2 *ball) {
    mx_handleLedge(ball);
    mx_handlePlatform(ball);
    mx_handleLvl2AdditionalSteps(ball);
    mx_handleLvl2Steps(ball);
    mx_handleLvl2Sleepers(ball);
}

void mx_handleCollisions2(Ball2 *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo) {
    if (ball->x - ball->radius < 0) {
        ball->x = ball->radius;
        ball->vx = 0;
    }
    if (ball->x + ball->radius > screenWidth) {
        ball->x = screenWidth - ball->radius;
        ball->vx = 0;
    }
    mx_handlelvl2FirstFloor(ball, screenWidth);
    handleLevel2Floors(ball);
    mx_handleLvl2Pillows(ball);
    mx_handleLvl2Wires(ball, renderInfo->renderer, renderInfo->state);
    mx_handleFirstCloudLvl2(ball, renderInfo->renderer, renderInfo->state);
    mx_handleSecondCloudLvl2(ball, renderInfo->renderer, renderInfo->state);
    mx_handleThirdCloudLvl2(ball, renderInfo->renderer, renderInfo->state);
    mx_handleFourthCloudLvl2(ball, renderInfo->renderer, renderInfo->state);
    handleLevel2Objects(ball);
    mx_handleFinishlvl2(ball, renderInfo->renderer, renderInfo->state, timeInfo->levelTime);
    if (ball->y - ball->radius < 0) {
        ball->y = ball->radius;
        ball->vy = -ball->vy * 0.8f;
    }
}
