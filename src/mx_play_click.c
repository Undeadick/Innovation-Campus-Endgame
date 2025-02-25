#include "../inc/header.h"

void mx_playClickSound(void) {
    static Mix_Chunk *clickSound = NULL;
    if (!clickSound)
    {
        clickSound = Mix_LoadWAV("resource/sounds/click.wav");
        if (!clickSound)
        {
            SDL_Log("Failed to load click sound: %s", Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, clickSound, 0);
}
