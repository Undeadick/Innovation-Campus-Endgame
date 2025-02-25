#include "../inc/header.h"

static int mx_init_sdl_core(void) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
		printf("SDL core could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}
	return 1;
}

static int mx_init_sdl_img(void) {
	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP) &
		(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP))) {
		printf("SDL_image could not initialize! IMG_Error: %s\n", IMG_GetError());
		SDL_Quit();
		return 0;
	}
	return 1;
}

static int mx_init_sdl_mixer(void) {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! Mix_Error: %s\n", Mix_GetError());
		IMG_Quit();
		SDL_Quit();
		return 0;
	}
	return 1;
}

static int mx_init_sdl_ttf(void) {
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
		Mix_CloseAudio();
		IMG_Quit();
		SDL_Quit();
		return 0;
	}
	return 1;
}

static SDL_Window* mx_create_window(const char* title, int width, int height) {
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		TTF_Quit();
		Mix_CloseAudio();
		IMG_Quit();
		SDL_Quit();
	}
	return window;
}

static SDL_Renderer* mx_create_renderer(SDL_Window* window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		TTF_Quit();
		Mix_CloseAudio();
		IMG_Quit();
		SDL_Quit();
	}
	return renderer;
}

SDL_Window* mx_init_sdl(const char* title, int width, int height, SDL_Renderer** renderer) {
	if (!mx_init_sdl_core() || 
	!mx_init_sdl_img() || 
	!mx_init_sdl_mixer() || 
	!mx_init_sdl_ttf())
		return NULL;

	SDL_Window* window = mx_create_window(title, width, height);
	if (!window) return NULL;

	*renderer = mx_create_renderer(window);
	if (!*renderer) {
		SDL_DestroyWindow(window);
		return NULL;
	}

	return window;
}
