#include "../inc/header.h"

void mx_renderBall(SDL_Renderer *renderer, Ball *ball, SDL_Texture *ballTexture) {
    SDL_Rect dstRect = {
        (int)(ball->x - ball->radius),
        (int)(ball->y - ball->radius),
        ball->radius * 2,
        ball->radius * 2
    };

    SDL_RenderCopy(renderer, ballTexture, NULL, &dstRect);
}
