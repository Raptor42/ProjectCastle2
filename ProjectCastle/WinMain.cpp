#include "WinMain.h"
#include <iostream>
#include <vector>
#include <string>





#include <SFML/Graphics.hpp>


int WinMain()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test Game" /*, sf::Style::Titlebar | sf::Style::Close*/);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("segoeuib.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	sf::Text gridSize;
	sf::Text screenSizeText;
	sf::Text colorSize;
	sf::Text squareSize;

	gridSize.setFont(font);
	screenSizeText.setFont(font);
	colorSize.setFont(font);
	squareSize.setFont(font);

	gridSize.setCharacterSize(40);
	screenSizeText.setCharacterSize(40);
	colorSize.setCharacterSize(40);
	squareSize.setCharacterSize(40);

	gridSize.setPosition(10, 10);
	screenSizeText.setPosition(10, 60);
	colorSize.setPosition(10, 110);
	squareSize.setPosition(10, 160);

	gridSize.setFillColor(sf::Color::Black);
	screenSizeText.setFillColor(sf::Color::Black);
	colorSize.setFillColor(sf::Color::Black);
	squareSize.setFillColor(sf::Color::Black);



	while (window.isOpen())
	{

		sf::Vector2u screenSize = window.getSize();
		unsigned int screenWidth = screenSize.x;
		unsigned int screenHeight = screenSize.y;

		std::string screenSizeString = "Screen Size: (" + std::to_string(screenWidth) + "," + std::to_string(screenHeight) + ")";
		screenSizeText.setString(screenSizeString);

		int squareLength = 20;

		std::string squareSizeString = "Square Size: " + std::to_string(squareLength);
		squareSize.setString(squareSizeString);

		int gridXSize = screenWidth / squareLength;
		int gridYSize = screenHeight / squareLength;

		std::string gridSizeString = "Grid Size: (" + std::to_string(gridXSize) + "," + std::to_string(gridYSize) + ")";
		gridSize.setString(gridSizeString);

		int colorXStep = 255 / gridXSize;
		int colorYStep = 255 / gridYSize;

		std::string colorSizeString = "Colour Step Size: (" + std::to_string(colorXStep) + "," + std::to_string(colorYStep) + ")";
		colorSize.setString(colorSizeString);
		

		std::vector<std::vector<sf::RectangleShape>> grid(gridXSize, std::vector<sf::RectangleShape>(gridYSize));

		for (int i = 0; i < gridXSize; i++) {
			for (int j = 0; j < gridYSize; j++) {
				grid[i][j].setSize(sf::Vector2f(squareLength, squareLength));
				grid[i][j].setPosition(i*squareLength, j*squareLength);
				grid[i][j].setFillColor(sf::Color((colorXStep*i), (colorYStep*j), 128));
			}
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < gridXSize; i++) {
			for (int j = 0; j < gridYSize; j++) {
				window.draw(grid[i][j]);
			}
		}
		window.draw(squareSize);
		window.draw(colorSize);
		window.draw(gridSize);
		window.draw(screenSizeText);
		window.display();
	}

	return 0;
}


main::~main()
{
}
