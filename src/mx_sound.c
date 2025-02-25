#include "../inc/header.h"

void mx_playBackgroundMusic(const char *filePath) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        SDL_Log("Failed to initialize SDL_mixer: %s", Mix_GetError());
        return;
    }

    Mix_Music *music = Mix_LoadMUS(filePath);
    if (!music)
    {
        SDL_Log("Failed to load music: %s", Mix_GetError());
        return;
    }
    Mix_PlayMusic(music, -1);
}
