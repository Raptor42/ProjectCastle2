#include "isometricSprite.h"
#include <SFML/Graphics.hpp>

namespace castle {


	isometricSprite::isometricSprite(int x, int y, int z=0) { //x, y, z in game board coordinates, player spawns at (0,0,0)
		mXpos = x;
		mYpos = y;
		mZpos = z;
	}


	isometricSprite::~isometricSprite() {
	}

	int isometricSprite::getXpos() {
		return mXpos;
	}

	int isometricSprite::getYpos() {
		return mYpos;
	}

	int isometricSprite::getZpos() {
		return mZpos;
	}

	void isometricSprite::setXPos(int x) {
		mXpos = x;
	}

	void isometricSprite::setYPos(int y) {
		mYpos = y;
	}

	void isometricSprite::setZPos(int z) {
		mZpos = z;
	}

	sf::Texture isometricSprite::getLeftTexture() {
		return mLeftTexture;
	}

	sf::Texture isometricSprite::getRightTexture() {
		return mRightTexture;
	}

	sf::Texture isometricSprite::getFloorTexture() {
		return mFloorTexture;
	}

	sf::Texture isometricSprite::getRoofTexture() {
		return mRoofTexture;
	}

	void isometricSprite::setLeftTexture(sf::Texture newTexture) {
		mLeftTexture = newTexture;
	}

	void isometricSprite::setRightTexture(sf::Texture newTexture) {
		mRightTexture = newTexture;
	}

	void isometricSprite::setFloorTexture(sf::Texture newTexture) {
		mFloorTexture = newTexture;
	}

	void isometricSprite::setRoofTexture(sf::Texture newTexture) {
		mRoofTexture = newTexture;
	}

	sf::Transform leftSide(   1, 0, 0,
						   -0.5, 1, 0,
							  0, 0, 1);
	sf::Transform rightSide(  1, 0, 0,
						    0.5, 1, 0,
							  0, 0, 1);
	sf::Transform topSide(  1,  -1, 0,
						  0.5, 0.5, 0,
						    0,   0, 1);
}

