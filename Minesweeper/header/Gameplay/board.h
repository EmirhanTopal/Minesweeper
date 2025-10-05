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
			const static int numOfRows = 12; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int numOfColumns = 12; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez

			//background
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			std::string backgroundTexturePath = "assets/textures/pokemon_bg.png";
			float background_pos_x = 0.0f;
			float background_pos_y = 0.0f;

			//cell
			Cell *cellArray[numOfRows][numOfColumns];

		public:
			bool isValueChanged = true;

			Board();
			void initialize();
			void initVariables();
			void render(sf::RenderWindow &_render_window);
			float getCellSizeWidth();
			float getCellSizeHeight();
			void fillBoard();
			void fillWithMines();
			void setCellValues();
			int cellAroundControl(int _i, int _j);
			void setCellBombValue(int _i, int _j, int _bomb_count);
			
	};
}