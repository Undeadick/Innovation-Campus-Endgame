#include "../inc/header.h"

void mx_playVicSound(void) {
    static Mix_Chunk *vicSound = NULL;
    if (!vicSound)
    {
        vicSound = Mix_LoadWAV("resource/sounds/victory.mp3");
        if (!vicSound)
        {
            SDL_Log("Failed to load vic sound: %s", Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, vicSound, 0);
}
