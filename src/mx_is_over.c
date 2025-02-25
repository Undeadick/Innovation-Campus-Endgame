#include "../inc/header.h"

bool mx_isCursorOverButton(SDL_Rect btn, int x, int y) {
    bool isOver = (x >= btn.x && 
		x <= btn.x + btn.w && 
		y >= btn.y && 
		y <= btn.y + btn.h);
    return isOver;
}
