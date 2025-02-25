#include "../inc/header.h"

void mx_playBounceSound(void) {
    static Mix_Chunk *bounceSound = NULL;
    if (!bounceSound)
    {
        bounceSound = Mix_LoadWAV("resource/sounds/bounce.mp3");
        if (!bounceSound)
        {
            SDL_Log("Failed to load vic sound: %s", Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, bounceSound, 0);
}
