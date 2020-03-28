#pragma once
#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "player.h" 
#include "graphics.h"

class HUD {
public:
	HUD();
	HUD(Graphics& graphics, Player& player);
	void update(int elapsedTime);
	void draw(Graphics& graphics);

private:
	Player _player;

	//health HUD sprites
	Sprite _healthBarSprite;
	Sprite _healthNumber1;
	Sprite _currentHealthBar;

	//EXP HUD sprites
	Sprite _lvWord;
	Sprite _lvNumber;
	Sprite _expBar;

	//Weapon HUD Sprites
	Sprite _slash;
	Sprite _dashes;
};

#endif

