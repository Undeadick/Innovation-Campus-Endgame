#include "../inc/header.h"

void mx_renderRenderTexture(RenderTexture *renderTexture, int x, int y) {
    SDL_Rect dstRect = { x, y, renderTexture->width, renderTexture->height };
    SDL_RenderCopy(renderTexture->renderer, renderTexture->texture, NULL, &dstRect);
}
