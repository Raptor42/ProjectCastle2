#pragma once

#include <SFML/Graphics.hpp>

namespace castle {
	class isometricSprite
	{
	public:
		isometricSprite(int x, int y, int z);
		~isometricSprite();

		int getXpos();
		int getYpos();
		int getZpos();

		void setXPos(int x);
		void setYPos(int y);
		void setZPos(int z);

		sf::Texture getLeftTexture();
		sf::Texture getRightTexture();
		sf::Texture getFloorTexture();
		sf::Texture getRoofTexture();

		void setLeftTexture(sf::Texture newTexture);
		void setRightTexture(sf::Texture newTexture);
		void setFloorTexture(sf::Texture newTexture);
		void setRoofTexture(sf::Texture newTexture);

	private:
		int mXpos;
		int mYpos;
		int mZpos;

		sf::Texture mLeftTexture;
		sf::Texture mRightTexture;
		sf::Texture mFloorTexture;
		sf::Texture mRoofTexture;

		sf::Transform leftSide;
		sf::Transform rightSide;
		sf::Transform topside;

	};

}

