#include "../inc/header.h"

void mx_destroyRenderTexture(RenderTexture *renderTexture) {
    if (renderTexture) {
        if (renderTexture->texture) {
            SDL_DestroyTexture(renderTexture->texture);
        }
        free(renderTexture);
    }
}
