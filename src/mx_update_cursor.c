#include "../inc/header.h"

static SDL_Cursor *getCursor(SDL_SystemCursor type) {
	static SDL_Cursor *cursors[2] = {NULL, NULL};
	if (!cursors[type]) cursors[type] = SDL_CreateSystemCursor(type);
	return cursors[type];
}

static bool isCursorOnButton(int x, int y, SDL_Rect btn) {
    bool isOver = (x >= btn.x && 
		x <= btn.x + btn.w && 
		y >= btn.y && 
		y <= btn.y + btn.h);
    return isOver;
}

void mx_updateCursor(SDL_Renderer *renderer, int mouseX, int mouseY) {
	SDL_Rect buttons[] = {
		{245, 115, 350, 105}, {245, 265, 350, 105}, {45, 585, 260, 80},
		{1189, 650, 66, 46}, {18, 21, 100, 100}
	};

	SDL_Cursor *cursor = getCursor(SDL_SYSTEM_CURSOR_ARROW);
	for (int i = 0; i < 5; i++) {
		if (isCursorOnButton(mouseX, mouseY, buttons[i])) {
			cursor = getCursor(SDL_SYSTEM_CURSOR_HAND);
			break;
		}
	}
	SDL_SetCursor(cursor);
	SDL_RenderPresent(renderer);
}
