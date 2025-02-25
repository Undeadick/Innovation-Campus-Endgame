#include "../inc/header.h"

void mx_renderTriangleButton(SDL_Renderer *renderer, int triangleButtonX, int triangleButtonY) {
    RenderTexture *triangleButtonTexture = mx_createRenderTexture(renderer, 100, 120);
    if (!triangleButtonTexture) return;

    if (mx_loadImageToRenderTexture(triangleButtonTexture, "resource/img/triangle.png") != 0) {
        mx_destroyRenderTexture(triangleButtonTexture);
        return;
    }

    mx_renderRenderTexture(triangleButtonTexture, triangleButtonX, triangleButtonY);
    mx_destroyRenderTexture(triangleButtonTexture);
}
