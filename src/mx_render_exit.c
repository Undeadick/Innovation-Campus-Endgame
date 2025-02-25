#include "../inc/header.h"

void mx_renderExitButton(SDL_Renderer *renderer, int buttonX, int buttonY) {
    RenderTexture *exitButtonTexture = mx_createRenderTexture(renderer, 350, 105);
    if (!exitButtonTexture) return;

    if (mx_loadImageToRenderTexture(exitButtonTexture, "resource/img/exit.png") != 0) {
        mx_destroyRenderTexture(exitButtonTexture);
        return;
    }

    mx_renderRenderTexture(exitButtonTexture, buttonX, buttonY);
    mx_destroyRenderTexture(exitButtonTexture);
}
