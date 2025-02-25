#include "../inc/header.h"

void mx_renderHTPButton(SDL_Renderer *renderer, int buttonX, int buttonY) {
    RenderTexture *htpButtonTexture = mx_createRenderTexture(renderer, 260, 80);
    if (!htpButtonTexture) return;

    if (mx_loadImageToRenderTexture(htpButtonTexture, "resource/img/htp.png") != 0) {
        mx_destroyRenderTexture(htpButtonTexture);
        return;
    }

    mx_renderRenderTexture(htpButtonTexture, buttonX, buttonY);
    mx_destroyRenderTexture(htpButtonTexture);
}
