#include "level.h"

//default constructor
Level::Level() {}

//custom constructor. Assign some local variables and pass the mapName and the graphics object to the loadMap method.
Level::Level(string mapName, Vector2 spawnPoint, Graphics& graphics) :
	_mapName(mapName),
	_spawnPoint(spawnPoint),
	_size(Vector2(0, 0)) {

	this->loadMap(mapName, graphics);
}

Level::~Level() {}

//get the map name and create a texture using the image 'bkblue' Set the size to 1280x960
void Level::loadMap(string mapName, Graphics& graphics) {
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("bkBlue.png"));

	this->_size = Vector2(1280, 960); 
}

void Level::update(int elapsedTime) {

}

//create a source rectangle that is 64x64, fill it with the image, and repeat it until the max size of the screen is reached. Send all of it to the screen. 
void Level::draw(Graphics& graphics) {
	SDL_Rect sourceRect = { 0, 0, 64, 64 };
	SDL_Rect destRect;
	for (int x = 0; x < this->_size.x / 64; x++) {
		for (int y = 0; y < this->_size.y / 64; y++) {
			destRect.x = x * 64;
			destRect.y = y * 64;
			destRect.w = 64;
			destRect.h = 64;
			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);

		}
	}

}
