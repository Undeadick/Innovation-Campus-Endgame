#include "../inc/header.h"

void mx_pauseMusic(void) {
    if (Mix_PlayingMusic()) {
        Mix_PauseMusic();
    }
}
