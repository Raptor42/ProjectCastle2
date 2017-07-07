#include "WinMain.h"
#include <iostream>
#include <vector>
#include <string>





#include <SFML/Graphics.hpp>

namespace castle {
	int WinMain()
	{
		sf::RenderWindow window(sf::VideoMode(1920, 1050), "Test Game" /*, sf::Style::Titlebar | sf::Style::Close*/);
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

		gridSize.setFillColor(sf::Color::White);
		screenSizeText.setFillColor(sf::Color::Black);
		colorSize.setFillColor(sf::Color::Black);
		squareSize.setFillColor(sf::Color::Black);

		int o = 0;
		int k = 0;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

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

			int colorXStep = 255 / (gridXSize * 3);
			int colorYStep = 255 / (gridYSize * 3);

			std::string colorSizeString = "Colour Step Size: (" + std::to_string(colorXStep) + "," + std::to_string(colorYStep) + ")";
			colorSize.setString(colorSizeString);


			std::vector<std::vector<sf::RectangleShape>> grid(gridXSize, std::vector<sf::RectangleShape>(gridYSize));

			for (int i = 0; i < gridXSize; i++) {
				for (int j = 0; j < gridYSize; j++) {
					grid[i][j].setSize(sf::Vector2f(squareLength, squareLength));
					grid[i][j].setPosition(i*squareLength, j*squareLength);

					/*if ((colorXStep*i + o) >= 255)
						o = 0;

					if ((colorYStep*j + o) >= 255)
						o = 0;*/

					grid[i][j].setFillColor(sf::Color((colorXStep*i + o), (colorYStep*j - o), 128));
				}
			}

			k++;
			/*if (k==2){
				k = 0;*/
			o++;
			//}

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

}