#include "../inc/header.h"

static LevelTextures loadLevelTextures(SDL_Renderer *renderer) {
    LevelTextures textures = {NULL, NULL};
    SDL_Surface *lvlSurface = IMG_Load("resource/img/lvl1/lvl1.png");
    if (!lvlSurface) {
        SDL_Log("Failed to load level 1 image: %s", IMG_GetError());
        return textures;
    }
    textures.levelTexture = SDL_CreateTextureFromSurface(renderer, lvlSurface);
    SDL_FreeSurface(lvlSurface);
    if (!textures.levelTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return textures;
    }
    textures.ballTexture = IMG_LoadTexture(renderer, "resource/img/cat.png");
    if (!textures.ballTexture)
        SDL_Log("Failed to load ball texture: %s", SDL_GetError());
    return textures;
}

static void handleEvents(SDL_Event *event, int *running, int *isPaused, GameState *state) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            *running = 0;
            mx_stopAllMusic();
            *state = EXIT_GAME;
        } else if (event->type == SDL_KEYDOWN) {
            if (event->key.keysym.sym == SDLK_ESCAPE) {
                *running = 0;
                mx_stopAllMusic();
                *state = LEVEL_SELECT;
            } else if (event->key.keysym.sym == SDLK_p) {
                *isPaused = !(*isPaused);
                if (*isPaused)
                    mx_pauseMusic();
                else
                    mx_resumeMusic();
            }
        }
    }
}

static float updateDeltaTime(Uint32 *lastTime, float *levelTime) {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - *lastTime) / 1000.0f;
    *lastTime = currentTime;
    *levelTime += deltaTime;
    return deltaTime;
}

static void renderPauseScreen(SDL_Renderer *renderer, int winWidth, int winHeight) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);
    SDL_RenderFillRect(renderer, NULL);
    mx_renderText(renderer, "Paused", winWidth / 2, winHeight / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

void mx_createLvl1(SDL_Renderer *renderer, GameState *state) {
    LevelTextures textures = loadLevelTextures(renderer);
    if (!textures.levelTexture || !textures.ballTexture) return;
    *state = LVL_1;
    int winWidth, winHeight; SDL_GetRendererOutputSize(renderer, &winWidth, &winHeight);
    SDL_Rect dstRect = {0, 0, winWidth, winHeight}; SDL_ShowCursor(SDL_DISABLE);
    Ball ball; mx_initBall(&ball, 1099, 80, 20);
    Uint32 lastTime = SDL_GetTicks(); float levelTime = 0.0f;
    int running = 1, isPaused = 0; mx_playBackgroundMusic("resource/sounds/lvl_music.mp3");
    SDL_Event event;
    
    while (running && *state == LVL_1) {
        handleEvents(&event, &running, &isPaused, state);
        float deltaTime = updateDeltaTime(&lastTime, &levelTime);
        TimeInfo timeInfo = {deltaTime, levelTime};
        RenderInfo renderInfo = {renderer, state};
        
        SDL_RenderClear(renderer); SDL_RenderCopy(renderer, textures.levelTexture, NULL, &dstRect);
        mx_renderBall(renderer, &ball, textures.ballTexture);
        if (isPaused) { renderPauseScreen(renderer, winWidth, winHeight); continue; }
        mx_runBallLogic(&ball, &event, &timeInfo, &renderInfo);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(textures.levelTexture); SDL_DestroyTexture(textures.ballTexture); SDL_ShowCursor(SDL_ENABLE);
}
