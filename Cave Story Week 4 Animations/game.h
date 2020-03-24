#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <algorithm>
#include "animatedSprite.h"

//Game class holds all information about the game loop
using namespace std;

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	AnimatedSprite _player;
};


#endif