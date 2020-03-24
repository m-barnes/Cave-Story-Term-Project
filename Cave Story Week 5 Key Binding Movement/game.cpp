#include "game.h"

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

	this->_player = Player(graphics, 200, 200);
	

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//start the game loop timer
	while (true) {
		input.beginNewFrame();

		//beginning of the main game loop
		if (SDL_PollEvent(&event)) {
			//check to see if a key has been pressed. If so, create a keyDown event
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			//check to see if a key has released. If so, create a keyUp event
			if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT) {
				return;
			}
		}
		//if the key pressed was ESC, kill the window
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		//if the key held down was 'left,' move the player left
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		//if the key held down was 'right,' move the player right
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}

		//if either the 'left' or 'right' key is released, kill player movement 
		if(!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
		
	}
}

//define the draw method
void Game::draw(Graphics& graphics) {
	graphics.clear();
	this->_player.draw(graphics);
	graphics.flip();
}

//define the update method
void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}