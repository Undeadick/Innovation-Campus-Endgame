#include "../inc/header.h"

int mx_loadImageToRenderTexture(RenderTexture *renderTexture, const char *imagePath) {
    SDL_Surface *surface = IMG_Load(imagePath);
    if (!surface) {
        SDL_Log("Unable to load image: %s", IMG_GetError());
        return -1;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderTexture->renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
        return -1;
    }

    SDL_DestroyTexture(renderTexture->texture);
    renderTexture->texture = texture;

    return 0;
}
