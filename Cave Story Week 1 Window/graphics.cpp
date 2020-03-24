#include "graphics.h"
#include <SDL.h>

//graphics object meant to hold all related game graphics...stuff

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window,&this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}