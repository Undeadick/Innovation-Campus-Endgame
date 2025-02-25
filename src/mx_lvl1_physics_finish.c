#include "../inc/header.h"

void mx_handleFinish(Ball *ball, SDL_Renderer *renderer, GameState *state, float levelTime) {
    int x1 = 1, y1 = 649;
    int width = 160, height = 61;
    int x2 = x1 + width, y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {

        if (*state != FINISH_SCREEN) {
            *state = FINISH_SCREEN;
            mx_stopAllMusic();
            mx_playVicSound();

            mx_updateNextLevelStatus(1);
            mx_createFinishScreen(renderer, state, levelTime);
        }
    }
}
