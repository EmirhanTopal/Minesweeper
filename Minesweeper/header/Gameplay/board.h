#pragma once
#include "../../header/UI/UIElements/Button/Button.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <random>
#include "../../header/Gameplay/Cell.h"

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
			const static int numOfRows = 10; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int numOfColumns = 10; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez

			//background
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			std::string backgroundTexturePath = "assets/textures/pokemon_bg.png";
			float background_pos_x = 0.0f;
			float background_pos_y = 0.0f;

			//cell
			Cell *cellArray[numOfRows][numOfColumns];
			int flagCellCount = 0;

		public:
			Board();
			void initialize();
			void update(Event::EventPollingManager& _event_manager, sf::RenderWindow &_game_window);
			void initVariables();
			void render(sf::RenderWindow &_render_window);
			float getCellSizeWidth();
			float getCellSizeHeight();
			void fillBoard();
			void fillWithMines();
			void setCellValues();
			int cellAroundControl(int _i, int _j);
			void setCellBombValue(int _i, int _j, int _bomb_count);
			void onCellButtonClicked(sf::Vector2i _cell_array_pos, UI::MouseButtonType _button_type);
			void openCell(sf::Vector2i _cell_array_pos);
			void flagCell(sf::Vector2i _cell_array_pos);
			void openEmptyCells(int i, int j);
			void openBombCells();
	};
}