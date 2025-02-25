#include "../inc/header.h"

void mx_resumeMusic(void) {
    if (Mix_PausedMusic()) { 
        Mix_ResumeMusic();
    }
}
