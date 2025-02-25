#include "../inc/header.h"

RenderTexture* mx_createRenderTexture(SDL_Renderer *renderer, int width, int height) {
    RenderTexture *renderTexture = (RenderTexture*)malloc(sizeof(RenderTexture));
    if (!renderTexture) {
        SDL_Log("Unable to allocate memory for RenderTexture");
        return NULL;
    }

    renderTexture->renderer = renderer;
    renderTexture->width = width;
    renderTexture->height = height;
    renderTexture->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    if (!renderTexture->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        free(renderTexture);
        return NULL;
    }

    return renderTexture;
}
