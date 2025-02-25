#include "../inc/header.h"

static void mx_check_collision(Ball3 *ball, const SDL_Rect *steps, int count) {
    for (int i = 0; i < count; i++)
    {
        SDL_Rect platform = steps[i];
        if (ball->x + ball->radius > platform.x && 
            ball->x - ball->radius < platform.x + platform.w &&
            ball->y + ball->radius > platform.y && 
            ball->y - ball->radius < platform.y + platform.h)
        {
            if (ball->y + ball->radius - ball->vy <= platform.y) {
                ball->y = platform.y - ball->radius;
                ball->vy = 0;
                ball->onGround = true;
            }
            else if (ball->y - ball->radius >= platform.y + platform.h) {
                ball->y = platform.y + platform.h + ball->radius;
                ball->vy = 0;
            }
            else if (ball->x + ball->radius - ball->vx <= platform.x) {
                ball->x = platform.x - ball->radius;
                ball->vx = 0;
            }
            else if (ball->x - ball->radius - ball->vx >= platform.x + platform.w) {
                ball->x = platform.x + platform.w + ball->radius;
                ball->vx = 0;
            }
            return;
        }
    }
}

void mx_handleStepsLvl3(Ball3 *ball) {
    static const SDL_Rect steps[] = {
        {796, 523, 75, 17}, {640, 477, 71, 10}, {496, 437, 63, 10}, {349, 485, 61, 10}, {147, 551, 131, 19}};

    mx_check_collision(ball, steps, 5);
}
