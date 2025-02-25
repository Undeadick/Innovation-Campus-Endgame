#include "../inc/header.h"

static void updateTriangleState(bool *show, int *y, int btnY) {
	*show = true;
	*y = btnY + 5;
}

static void processTriangleVisibility(bool *show, int *y, int x, int yMouse) {
	SDL_Rect playBtn = {245, 115, 350, 105};
	SDL_Rect exitBtn = {245, 265, 350, 105};

	if (mx_isCursorOverButton(playBtn, x, yMouse)) {
		updateTriangleState(show, y, playBtn.y);
	} else if (mx_isCursorOverButton(exitBtn, x, yMouse)) {
		updateTriangleState(show, y, exitBtn.y);
	} else {
		*show = false;
	}
}

static void handleTriangleLogic(SDL_Event *e, bool *showTriangle, int *triangleButtonY, int mouseX) {
	if (e->type == SDL_MOUSEMOTION) {
		processTriangleVisibility(showTriangle, triangleButtonY, mouseX, e->motion.y);
	}
}

static bool processMenuEvents(SDL_Event *e, SDL_Renderer *renderer, GameState *state, bool *running) {
	if (e->type == SDL_QUIT) {
		*running = false;
		return false;
	}
	mx_handleButtonAction(e, renderer, SDL_GetWindowFromID(e->window.windowID), state);
	return true;
}

int mx_main_menu(SDL_Renderer *renderer, GameState *currentState) {
	*currentState = MAIN_MENU;
	SDL_Texture *bg = IMG_LoadTexture(renderer, "resource/img/bg.png");
	if (!bg) return -1;
	int playX = 245, playY = 115, exitX = 245, exitY = 265;
	int htpX = 45, htpY = 585, triX = 135, triY = 0;
	bool showTriangle = false, running = true;
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			handleTriangleLogic(&e, &showTriangle, &triY, x);
			if (!processMenuEvents(&e, renderer, currentState, &running)) return -1;
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bg, NULL, NULL);
		mx_renderPlayButton(renderer, playX, playY);
		mx_renderExitButton(renderer, exitX, exitY);
		mx_renderHTPButton(renderer, htpX, htpY);
		if (showTriangle) mx_renderTriangleButton(renderer, triX, triY);
		SDL_RenderPresent(renderer);
	}
	return 0;
}
