#include "../inc/header.h"

void mx_handleFinishLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state, float levelTime) {
    int x1 = 0, y1 = 658;
    int width = 158, height = 61;
    int x2 = x1 + width, y2 = y1 + height;
    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        if (*state != FINISH_SCREEN) {
            *state = FINISH_SCREEN;
            mx_stopAllMusic();
            mx_playVicSound();
            if(mx_isLevelCompleted(3)){
                mx_createFinishScreen(renderer, state, levelTime); 
            }
            else{
                mx_updateNextLevelStatus(3);
                mx_createFinishScreen(renderer, state, levelTime);
            }
        }
    }
}
