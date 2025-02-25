#ifndef HEADER_H
#define HEADER_H

// SDL2 Frameworks
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//System Libriaries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#define WINDOW_WIDTH         1280
#define WINDOW_HEIGHT        720

#define BUTTON_BACK_WIDTH    174
#define BUTTON_BACK_HEIGHT   52

#define BUTTON_LVL_WIDTH     150
#define BUTTON_LVL_HEIGHT    150

#define MAX_LEVELS 100

typedef struct {
    float x;
    float y;
    float radius;
    float vx;
    float vy;
    bool onGround;
} Ball;

typedef struct {
    float x;
    float y;
    float radius;
    float vx;
    float vy;
    bool onGround;
} Ball2;

typedef struct {
    float x;
    float y;
    float radius;
    float vx;
    float vy;
    bool onGround;
} Ball3;

typedef struct {
    SDL_Texture *texture;
    SDL_Rect rect;
} ButtonBack;

typedef struct {
    char *texture;
} Button;

typedef struct {
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    int width;
    int height;
} RenderTexture;

typedef struct {
    int level;
    char status[16];
} LevelStatus;

typedef struct s_LevelTextures {
    SDL_Texture *levelTexture;
    SDL_Texture *ballTexture;
} LevelTextures;

typedef enum {
    MAIN_MENU,
    LEVEL_SELECT,
    HTP_SCREEN,
    GAME_SCREEN,
    LVL_1,
    EXIT_GAME,
    FINISH_SCREEN,
    LVL_2,
    LVL_3,
} GameState;

typedef struct {
    float deltaTime;
    float levelTime;
} TimeInfo;

typedef struct {
    SDL_Renderer *renderer;
    GameState *state;
} RenderInfo;

SDL_Window* mx_init_sdl(const char* title, int width, int height, SDL_Renderer** renderer);
void mx_cleanup(SDL_Window *window, SDL_Renderer *renderer);

void mx_destroyRenderTexture(RenderTexture *renderTexture);
RenderTexture* mx_createRenderTexture(SDL_Renderer *renderer, int width, int height);
int mx_loadImageToRenderTexture(RenderTexture *renderTexture, const char *imagePath);
void mx_renderPlayButton(SDL_Renderer *renderer, int buttonX, int buttonY);
void mx_renderExitButton(SDL_Renderer *renderer, int buttonX, int buttonY);
void mx_renderRenderTexture(RenderTexture *renderTexture, int x, int y);

void mx_renderText(SDL_Renderer *renderer, const char *text, int x, int y);
void mx_renderBlackText(SDL_Renderer *renderer, const char *text, int x, int y);

void mx_renderHTPButton(SDL_Renderer *renderer, int buttonX, int buttonY);
void mx_renderTriangleButton(SDL_Renderer *renderer, int triangleButtonX, int triangleButtonY);
void mx_renderPlayButton(SDL_Renderer *renderer, int buttonX, int buttonY);
bool mx_isCursorOverButton(SDL_Rect btn, int x, int y);
int mx_main_menu(SDL_Renderer *renderer, GameState *currentState);

void mx_handleButtonAction(SDL_Event *event, SDL_Renderer *renderer, SDL_Window *window, GameState *state);
void mx_updateCursor(SDL_Renderer *renderer, int mouseX, int mouseY);
void mx_onExitPressed(SDL_Window *window, SDL_Renderer *renderer);
void mx_openHtpImage(SDL_Renderer *renderer, GameState *state);

// Music Functions
void mx_pauseMusic(void);
void mx_resumeMusic(void);
void mx_playClickSound(void);
void mx_playEndSound(void);
void mx_playVicSound(void);
void mx_playBounceSound(void);
void mx_playBackgroundMusic(const char *filePath);
void mx_stopAllMusic(void);

// Level select window
void mx_openPlayImage(SDL_Renderer *renderer, GameState *state);
ButtonBack mx_createButtonBack(SDL_Renderer *renderer, int x, int y);
void mx_renderButtonBack(SDL_Renderer *renderer, ButtonBack *button);
bool mx_handleButtonBackClick(ButtonBack *button, SDL_Event *event);
void mx_destroyButtonBack(ButtonBack *button);
void mx_updateCursorBack(ButtonBack *button, int mouseX, int mouseY);

// LVL 1
void mx_createLvl1Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state);
void mx_createLvl1(SDL_Renderer *renderer, GameState *state);

// LVL 1 Ball
void mx_initBall(Ball *ball, float x, float y, float radius);
void mx_handleCollisions(Ball *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo);
void mx_renderBall(SDL_Renderer *renderer, Ball *ball, SDL_Texture *ballTexture);
void mx_runBallLogic(Ball *ball, SDL_Event *event, TimeInfo *timeInfo, RenderInfo *renderInfo);

// LVL 1 Collision
void mx_handleCollisionsGround(Ball *ball, int screenWidth);
void mx_handleSteps(Ball *ball);
void mx_handlePillowSteps(Ball *ball);
void mx_handleCloudCollisions(Ball *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleNeedles(Ball *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleLava(Ball *ball, SDL_Renderer *renderer, GameState *state);

// LVL 2
void mx_createLvl2Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state);
void mx_renderLockedLvl2Button(SDL_Renderer *renderer);
void mx_createLvl2(SDL_Renderer *renderer, GameState *state);

// LVL 2 Ball
void mx_initBall2(Ball2 *ball, float x, float y, float radius);
void mx_handleCollisions2(Ball2 *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo);
void applyGravity2(Ball2 *ball, float deltaTime);
void applyFriction2(Ball2 *ball);
void mx_renderBall2(SDL_Renderer *renderer, Ball2 *ball, SDL_Texture *ballTexture);
void mx_runBall2Logic(Ball2 *ball, SDL_Event *event, TimeInfo *timeInfo, RenderInfo *renderInfo);

// LVL2 Collision
void mx_handlelvl2FirstFloor(Ball2 *ball, int screenWidth);
void mx_handlelvl2SecondFloor(Ball2 *ball);
void mx_handlelvl2ThirdFloor(Ball2 *ball);
void mx_handlelvl2FourthFloor(Ball2 *ball);
void mx_handlelvl2FifthFloor(Ball2 *ball);
void mx_handleLvl2Pillows(Ball2 *ball);
void mx_handleLvl2Wires(Ball2 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleFirstCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleSecondCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleThirdCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleFourthCloudLvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleLedge(Ball2 *ball);
void mx_handlePlatform(Ball2 *ball);
void mx_handleLvl2AdditionalSteps(Ball2 *ball);
void mx_handleLvl2Steps(Ball2 *ball);
void mx_handleLvl2Sleepers(Ball2 *ball);
void mx_handleFinishlvl2(Ball2 *ball, SDL_Renderer *renderer, GameState *state, float levelTime);

// LVL 3 
void mx_createLvl3Button(SDL_Renderer *renderer, SDL_Event *event, GameState *state);
void mx_renderLockedLvl3Button(SDL_Renderer *renderer);
void createLvl3(SDL_Renderer *renderer, GameState *state);

// LVL 3 Ball
void mx_initBall3(Ball3 *ball, float x, float y, float radius);
void mx_handleCollisions3(Ball3 *ball, int screenWidth, RenderInfo *renderInfo, TimeInfo *timeInfo);
void mx_renderBall3(SDL_Renderer *renderer, Ball3 *ball, SDL_Texture *ballTexture);
void mx_runBall3Logic(Ball3 *ball, SDL_Event *event, TimeInfo *timeInfo, RenderInfo *renderInfo);

// LVL 3 Collision
void mx_handleCloudsLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleAllGroundLvl3(Ball3 *ball);
void handleFirstStepLvl3(Ball3 *ball);
void handleSecondStepLvl3(Ball3 *ball);
void handleThirdStepLvl3(Ball3 *ball);
void handleFourthStepLvl3(Ball3 *ball);
void handleFifthStepLvl3(Ball3 *ball);
void mx_handleStepsLvl3(Ball3 *ball);
void mx_handleBoxes(Ball3 *ball);
void mx_handleLavaLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state);
void mx_handleFinishLvl3(Ball3 *ball, SDL_Renderer *renderer, GameState *state, float levelTime);

// Restart Function
void mx_restartLevel1(SDL_Renderer *renderer, GameState *state);
void mx_restartLevel2(SDL_Renderer *renderer, GameState *state);
void mx_restartLevel3(SDL_Renderer *renderer, GameState *state);

// Finish Screen Function
void mx_createContinueButton(SDL_Renderer *renderer, GameState *state);
void mx_createBackToMenuButton(SDL_Renderer *renderer, GameState *state);
void mx_createFinishScreen(SDL_Renderer *renderer, GameState *state, float elapsedTime);
void mx_handleFinish(Ball *ball, SDL_Renderer *renderer, GameState *state, float levelTime);

// Unlock level function
bool mx_isLevelUnlocked(int level);
void mx_updateNextLevelStatus(int finishedLevel);
bool mx_isLevelCompleted(int level);

#endif
