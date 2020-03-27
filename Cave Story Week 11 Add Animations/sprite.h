#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"
#include "globals.h"
#include "rectangle.h"

#include <SDL.h>
#include <string>

using namespace std;

class Sprite {
public:
	//default constructor NOT USED
	Sprite();
	//custom constructor. Grabs the spritesheet asset and parses out a specific rectangle (source x and y, width, height, posX, posY)
	Sprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);

	//a way to get rid of all derived sprite objects 
	virtual ~Sprite();

	//a way to update and clear out specific sprite objects
	virtual void update(); 

	//draw the sprite to a specific location
	void draw(Graphics& graphics, int x, int y); 

	//getter function to get a bounding box for quote
	const Rectangle getBoundingBox() const;

	//get function to figure out where the rectangles are colliding
	const sides::Side getCollisionSide(Rectangle& other) const;

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	Rectangle _boundingBox;
	float _x, _y;

private:
	

};

#endif
