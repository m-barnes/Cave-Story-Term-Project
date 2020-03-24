#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "globals.h"
#include "graphics.h"
#include <SDL.h>
#include <string>

using namespace std;

class Level {
public:
	//default constructor
	Level();

	//custom constructor
	Level(string mapName, Vector2 spawnPoint, Graphics& graphics);
	
	//destructor
	~Level();

	//update function for the level class
	void update(int elapsedTime);

	//draw function for the level class
	void draw(Graphics& graphics);

private:
	//instance some variables. mapname holds the name of the map loaded, spawnpoint is the spawnpoint on that map (x,y) and background texture is the texture created from that map. 
	string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	SDL_Texture* _backgroundTexture;

	//load the map. Pass to the function the mapname and a reference to the graphics object.
	void loadMap(string mapName, Graphics& graphics);
};





#endif
