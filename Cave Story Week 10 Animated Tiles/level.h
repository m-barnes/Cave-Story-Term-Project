#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "globals.h"
#include "graphics.h"	
#include "tile.h"
#include "tinyxml2.h"
#include "rectangle.h"
#include "slope.h"
#include "utils.h"
#include "animatedtile.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <SDL.h>
#include <string>

using namespace std;
using namespace tinyxml2;

//Tileset structure
struct Tileset {
	SDL_Texture* Texture;
	int FirstGid;
	
	Tileset() {
		this->FirstGid = -1;
	}

	Tileset(SDL_Texture* texture, int firstgid) {
		this->Texture = texture;
		this->FirstGid = firstgid;
	}
};

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

	//function for checking collisions
	vector<Rectangle> checkTileCollisions(const Rectangle& other);

	//function for checking slope collisions
	vector<Slope> checkSlopeCollisions(const Rectangle& other);

	//function to hold the spawnpoint parsed from map
	const Vector2 getPlayerSpawnPoint() const;

private:
	//instance some variables. mapname holds the name of the map loaded, spawnpoint is the spawnpoint on that map (x,y) and background texture is the texture created from that map, tileList is the list of tiles in a map, tilesets are the tile layers, collisionRects are the collection of rectangles that cause collision events, slopes is a collection of slopes that cause collision events. 
	string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	Vector2 _tileSize;
	SDL_Texture* _backgroundTexture;
	vector<Tile> _tileList;
	vector<Tileset> _tilesets;
	vector<Rectangle> _collisionRects;
	vector<Slope> _slopes;
	vector<AnimatedTile> _animatedTileList;
	vector<AnimatedTileInfo> _animatedTileInfo;

	//load the map. Pass to the function the mapname and a reference to the graphics object.
	void loadMap(string mapName, Graphics& graphics);

	Vector2 getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight);
};

#endif
