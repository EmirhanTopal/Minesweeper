#pragma once
#include "../../header/Gameplay/Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

namespace Gameplay
{
	class Board
	{
		private:
			//gameplay board
			sf::Texture boardTexture;
			sf::Sprite boardSprite;
			std::string boardTexturePath = "assets/textures/PokemonBoard2.png";
			float board_pos_x = 480.0f;
			float board_pos_y = 0.0f;
			const float boardPlayableWidth = 810.0f;
			const float boardPlayableHeight = 810.0f;
			const static int numOfRows = 12; // compile time da program�n anlayabilmesi i�in her member i�in ayn� ve de�i�tirilemez
			const static int numOfColumns = 12; // compile time da program�n anlayabilmesi i�in her member i�in ayn� ve de�i�tirilemez
			//const float boardHeight = 1080.f;

			//background
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			std::string backgroundTexturePath = "assets/textures/pokemon_bg.png";
			float background_pos_x = 0.0f;
			float background_pos_y = 0.0f;

			//cell
			Cell *cellArray[numOfRows][numOfColumns];

		public:
			Board();
			void initialize();
			void initVariables();
			void render(sf::RenderWindow &_render_window);
			float getCellSizeWidth();
			float getCellSizeHeight();
			void fillBoard();
			void fillWithMines();
	};
}