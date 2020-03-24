#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
	//create a global variable to handle the screen size
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//create a global variable to scale the sprites to 2x their size
	const float SPRITE_SCALE = 2.0f;
}

//an enumeration to set direction for all moving objects in the game (mostly Quote)
enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

//define a custom data structure called Vector2
struct Vector2 {
	//declare a couple of variables
	int x, y; 
	//define a default constructor
	Vector2():
		x(0), y(0)
	{}
	//custom constructor for the structure
	Vector2(int x, int y) :
		x(x), y(y)
	{}
	//zero version of the custom constructor
	Vector2 zero() {
		return Vector2(0, 0);
	}
};






#endif
