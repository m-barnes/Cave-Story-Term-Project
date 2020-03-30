#pragma once
#ifndef BAT_H
#define BAT_H

#include "enemy.h"

class Bat : public Enemy {
public:
	//default constructor
	Bat();
	//custom constructor
	Bat(Graphics& graphics, Vector2 spawnPoint);

	void update(int elapsedTime, Player& player);
	void draw(Graphics& graphics);
	//handles the health of the player indirectly
	void touchPlayer(Player* player);

	void animationDone(string currentAnimation);
	void setupAnimations();

private:
	float _startingX;
	float _startingY;
	bool _shouldMove;
};


#endif
