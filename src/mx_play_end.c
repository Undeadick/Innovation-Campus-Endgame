#include "../inc/header.h"

void mx_playEndSound(void) {
    static Mix_Chunk *endSound = NULL;
    if (!endSound)
    {
        endSound = Mix_LoadWAV("resource/sounds/end.mp3");
        if (!endSound)
        {
            SDL_Log("Failed to load end sound: %s", Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, endSound, 0);
}
