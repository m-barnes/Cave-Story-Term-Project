#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedSprite.h"
#include "graphics.h"
#include "globals.h"


class Player : public AnimatedSprite {

public:
	//default constructor
	Player();

	//custom constructor
	Player(Graphics& graphics, float x, float y);
	
	//draw method for the player class
	void draw(Graphics& graphics);

	//update method for the player class
	void update(float elapsedTime);

	//move the player left -delta x
	void moveLeft();
	//move the player right +delta x
	void moveRight();
	//stop the player movement
	void stopMoving();

	//override the abstract functions in animatedSprite
	virtual void animationDone(string currentAnimation); 
	virtual void setupAnimations();

private:
	float _dx, _dy;
	Direction _facing;
};

#endif

