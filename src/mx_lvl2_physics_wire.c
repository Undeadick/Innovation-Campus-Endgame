#include "../inc/header.h"

static void handleWireOne(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 231; 
    int y1 = 661;
    int width = 163; 
    int height = 51;
    int x2 = x1 + width; 
    int y2 = y1 + height;

    if (ball->x + ball->radius >= x1 &&
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel2(renderer, state);
    }
}

static void handleWireTwo(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 625; 
    int y1 = 653;
    int width = 346; 
    int height = 41;
    int x2 = x1 + width; 
    int y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel2(renderer, state);
    }
}

static void handleWireThird(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    int x1 = 297; 
    int y1 = 277;
    int width = 258; 
    int height = 38;
    int x2 = x1 + width; 
    int y2 = y1 + height;

    if (ball->x + ball->radius >= x1 && 
        ball->x - ball->radius <= x2 &&
        ball->y + ball->radius >= y1 && 
        ball->y - ball->radius <= y2) {
        
        mx_restartLevel2(renderer, state);
    }
}

void mx_handleLvl2Wires(Ball2 *ball, SDL_Renderer *renderer, GameState *state) {
    handleWireOne(ball, renderer, state);
    handleWireTwo(ball, renderer, state);
    handleWireThird(ball, renderer, state);
}
