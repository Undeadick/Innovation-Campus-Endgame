#include "../inc/header.h"

void mx_onExitPressed(SDL_Window *window, SDL_Renderer *renderer) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();

    exit(0); 
}
