#include "../inc/header.h"

static void processEvents(SDL_Event *e, GameState *state, SDL_Renderer *renderer, SDL_Window *window) {
	while (SDL_PollEvent(e)) {
		if (e->type == SDL_QUIT) *state = EXIT_GAME;
		mx_handleButtonAction(e, renderer, window, state);
	}
}

int main(void) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	GameState currentState = MAIN_MENU;
	SDL_Event e;
	const int frameDelay = 1000 / 60;

	window = mx_init_sdl("MeowEscape", WINDOW_WIDTH, WINDOW_HEIGHT, &renderer);
	if (!window || mx_main_menu(renderer, &currentState)) return EXIT_FAILURE;

	while (currentState != EXIT_GAME) {
		Uint32 frameStart = SDL_GetTicks();
		processEvents(&e, &currentState, renderer, window);
		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
	}

	mx_cleanup(window, renderer);
	return EXIT_SUCCESS;
}
