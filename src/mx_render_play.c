#include "../inc/header.h"

void mx_renderPlayButton(SDL_Renderer *renderer, int buttonX, int buttonY) {
    RenderTexture *playButtonTexture = mx_createRenderTexture(renderer, 350, 105);
    if (!playButtonTexture) return;

    if (mx_loadImageToRenderTexture(playButtonTexture, "resource/img/play.png") != 0) {
        mx_destroyRenderTexture(playButtonTexture);
        return;
    }

    mx_renderRenderTexture(playButtonTexture, buttonX, buttonY);
    mx_destroyRenderTexture(playButtonTexture);
}
