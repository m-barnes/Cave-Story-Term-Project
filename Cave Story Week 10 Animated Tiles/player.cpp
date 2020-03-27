#include "player.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
	const float	GRAVITY = 0.002f;
	const float GRAVITY_CAP = 0.8f;
	const float JUMP_SPEED = 0.7f;

}

//default constructor
Player::Player() {}

//custom constructor
Player::Player(Graphics& graphics, Vector2 spawnPoint) :
	AnimatedSprite(graphics, "MyChar.png", 0, 0, 16, 16, spawnPoint.x, spawnPoint.y, 100),
	_dx(0),
	_dy(0),
	_facing(Direction::RIGHT),
	_grounded(false)
{
	graphics.loadImage("MyChar.png");
	this->setupAnimations();
	
}

//draw function that calls the draw function for AnimatedSprite
void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

//update function that calls the update function for AnimatedSprite
void Player::update(float elapsedTime) {
	if (this->_dy <= player_constants::GRAVITY_CAP) {
		this->_dy += player_constants::GRAVITY * elapsedTime;
	}
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = Direction::LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = Direction::RIGHT;
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == Direction::RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::jump() {
	//check to see that Quote is on the ground
	if (this->_grounded) {
		//set deltaY to 0
		this->_dy = 0;
		//reset deltaY take away the .7 and move him 'up'
		this->_dy -= player_constants::JUMP_SPEED;
		//change grounded because Quote is now in the air
		this->_grounded = false;
	}
}

//animationDone function to signal an animation has finished
void Player::animationDone(string currentAnimation) {

}

//our good friend the setupAnimations function
void Player::setupAnimations() {	
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

//Handles collisions with all tiles the player is colliding with
void Player::handleTileCollisions(vector<Rectangle>& others) {
	//Figure out where the collision is happening and move the player 
	for (int i = 0; i < others.size(); i++) {
		sides::Side collisionSide = Sprite::getCollisionSide(others.at(i));
		if (collisionSide != sides::Side::NONE) {
			switch (collisionSide) {
			case sides::Side::TOP:
				this->_y = others.at(i).getBottom() + 1;
				this->_dy = 0;
				break;
			case sides::Side::BOTTOM:
				this->_y = others.at(i).getTop() - this->_boundingBox.getHeight() - 1;
				this->_dy = 0;
				this->_grounded = true;
				break;
			case sides::Side::LEFT:
				this->_x = others.at(i).getRight() + 1;
				break;
			case sides::Side::RIGHT:
				this->_x = others.at(i).getLeft() - this->_boundingBox.getWidth() - 1;
				break;
			}
		}
	}
}

//void handleSlopeCollisions
//Handles collisions with ALL slopes the player is colliding with
void Player::handleSlopeCollisions(vector<Slope> &others) {
	for (int i = 0; i < others.size(); i++) {
		int b = (others.at(i).getP1().y - (others.at(i).getSlope() * fabs(others.at(i).getP1().x)));
		int centerX = this->_boundingBox.getCenterX();
		int newY = (others.at(i).getSlope() * centerX) + b - 8;

		if (this->_grounded) {
			this->_y = newY - this->_boundingBox.getHeight();
			this->_grounded = true;
		}
	}
}

//getter function to retrieve the value of x
const float Player::getX() const {
	return this->_x;
}

//getter function to retrieve the value of y
const float Player::getY() const {
	return this->_y;
}

