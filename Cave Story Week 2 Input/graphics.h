#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

//forward the SDL Window and Renderer
struct SDL_Window;
struct SDL_Renderer;

//create a graphics class
class Graphics {

//public methods are available to all parts of the application.
public:
	Graphics();
	~Graphics();

//private methods are available only to the class or any subclass derived from that class
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;


};

#endif