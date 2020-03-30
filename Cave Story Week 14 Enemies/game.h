#pragma once
#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "input.h"
#include "player.h"
#include "level.h"
#include "hud.h"
#include <SDL.h>
#include <algorithm>

//Game class holds all information about the game loop
using namespace std;

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	Level _level;
	Player _player;
	HUD _hud;

	Graphics _graphics;
	
};


#endif