#include "../inc/header.h"

static LevelTextures loadLevel2Textures(SDL_Renderer *renderer) {
    LevelTextures textures = {NULL, NULL};
    SDL_Surface *lvl2Surface = IMG_Load("resource/img/lvl2/lvl2.png");
    if (!lvl2Surface) {
        SDL_Log("Failed to load level 2 image: %s", IMG_GetError());
        return textures;
    }
    textures.levelTexture = SDL_CreateTextureFromSurface(renderer, lvl2Surface);
    SDL_FreeSurface(lvl2Surface);
    if (!textures.levelTexture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return textures;
    }
    textures.ballTexture = IMG_LoadTexture(renderer, "resource/img/cat.png");
    if (!textures.ballTexture)
        printf("Failed to load texture: %s\n", SDL_GetError());
    return textures;
}

static void handleLevel2Events(SDL_Event *event, int *running, int *isPaused, GameState *state) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            *running = 0;
            mx_stopAllMusic();
            *state = EXIT_GAME;
        }
        if (event->type == SDL_KEYDOWN) {
            if (event->key.keysym.sym == SDLK_ESCAPE) {
                *running = 0;
                mx_stopAllMusic();
                *state = LEVEL_SELECT;
            }
            if (event->key.keysym.sym == SDLK_p) {
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

static void renderPauseScreen(SDL_Renderer *renderer, int windowWidth, int windowHeight) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);
    SDL_RenderFillRect(renderer, NULL);
    mx_renderText(renderer, "Paused", windowWidth / 2, windowHeight / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

void mx_createLvl2(SDL_Renderer *renderer, GameState *state) {
    LevelTextures textures = loadLevel2Textures(renderer);
    if (!textures.levelTexture || !textures.ballTexture) return;
    *state = LVL_2;
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    SDL_Rect dstRect = {0, 0, windowWidth, windowHeight};
    SDL_ShowCursor(SDL_DISABLE);
    Ball2 ball;
    mx_initBall2(&ball, 25, 650, 20);
    Uint32 lastTime = SDL_GetTicks();
    float levelTime = 0.0f;
    int running = 1, isPaused = 0;
    mx_playBackgroundMusic("resource/sounds/lvl_2.mp3");
    SDL_Event event;
    while (running && *state == LVL_2) {
        handleLevel2Events(&event, &running, &isPaused, state);
        float deltaTime = updateDeltaTime(&lastTime, &levelTime);
        TimeInfo timeInfo = {deltaTime, levelTime};
        RenderInfo renderInfo = {renderer, state};
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textures.levelTexture, NULL, &dstRect);
        mx_renderBall2(renderer, &ball, textures.ballTexture);
        if (isPaused) { renderPauseScreen(renderer, windowWidth, windowHeight); continue; }
        mx_runBall2Logic(&ball, &event, &timeInfo, &renderInfo);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(textures.levelTexture);
    SDL_DestroyTexture(textures.ballTexture);
    SDL_ShowCursor(SDL_ENABLE);
}
