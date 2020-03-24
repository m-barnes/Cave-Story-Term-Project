#include "game.h"
#include "graphics.h"
#include "input.h"
#include <SDL.h>
#include <algorithm>

//Game class holds all information about the game loop
using namespace std;
//create a namespace to hold values for FPS and Max Frame Time
namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
//Game constructor
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING); 
	this->gameLoop();
}

//Game deconstructor
Game::~Game() {

}

//initialize game loop objects
void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//start the game loop timer
	while (true) {
		input.beginNewFrame();

		//beginning of the main game loop
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		
	}
}

//define the draw method
void Game::draw(Graphics& graphics) {

}

//define the update method
void Game::update(float elapsedTime) {

}