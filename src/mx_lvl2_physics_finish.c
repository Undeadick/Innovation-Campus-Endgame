#include "../inc/header.h"

void mx_handleFinishlvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state, float levelTime) {
    int x1 = 0, y1 = 0;
    int width = 47, height = 128;
    int x2 = x1 + width, y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {

        if (*state != FINISH_SCREEN) {
            *state = FINISH_SCREEN;
            mx_stopAllMusic();
            mx_playVicSound();
            if(mx_isLevelCompleted(2)){
                mx_createFinishScreen(renderer, state, levelTime); 
            }
            else{
                mx_updateNextLevelStatus(2);
                mx_createFinishScreen(renderer, state, levelTime);
            }
        }
    }
}
