#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedSprite.h"
#include "graphics.h"
#include "globals.h"
#include "slope.h"

using namespace std;

class Player : public AnimatedSprite {

public:
	//default constructor
	Player();

	//custom constructor
	Player(Graphics& graphics, Vector2 spawnPoint);
	
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
	//make player look up
	void lookUp();
	//make player stop looking up
	void stopLookingUp();
	//make player look down
	void lookDown();
	//make player stop looking down
	void stopLookingDown();
	//make Quote jump!
	void jump();



	//override the abstract functions in animatedSprite
	virtual void animationDone(string currentAnimation); 
	virtual void setupAnimations();
	void handleTileCollisions(vector<Rectangle> &others);
	void handleSlopeCollisions(vector<Slope> &others);

	const float getX() const;
	const float getY() const;

private:
	float _dx, _dy;
	Direction _facing;
	bool _grounded;
	bool _lookingUp = false;
	bool _lookingDown = false;
};

#endif

