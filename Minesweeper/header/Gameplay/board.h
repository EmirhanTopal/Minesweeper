#pragma once
#include "../../header/UI/UIElements/Button/Button.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <random>
#include "../../header/Gameplay/Cell.h"

namespace Gameplay
{
	enum BoardState
	{
		FIRSTCELL,
		PLAYING,
		COMPLETED
	};

	class GameplayManager;
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
<<<<<<< Updated upstream
			const static int numOfRows = 2; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int numOfColumns = 2; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int randMinBombValue = 1;
			const static int randMaxBombValue = 1;
=======
			const static int numOfRows = 8; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int numOfColumns = 8; // compile time da programýn anlayabilmesi için her member için ayný ve deðiþtirilemez
			const static int randMinBombValue = 8;
			const static int randMaxBombValue = 10;
>>>>>>> Stashed changes
			BoardState _boardState;
			sf::Vector2i firstCellVector { -1, -1};

			//background
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			std::string backgroundTexturePath = "assets/textures/SummerPokemon.png";
			float background_pos_x = 0.0f;
			float background_pos_y = 0.0f;

			//cell
			Cell *cellArray[numOfRows][numOfColumns];
			int flagCellCount = 0;

<<<<<<< Updated upstream
=======
			//mine
			int minesCount = 0;


>>>>>>> Stashed changes
			//GameplayManager
			GameplayManager *_gameplayManager;

		public:
			Board(GameplayManager* _gameplayManager);
			void initialize(GameplayManager* _gameplayManager);
			void initVariables(GameplayManager* _gameplayManager);
			void update(Event::EventPollingManager& _event_manager, sf::RenderWindow &_game_window);
			void render(sf::RenderWindow &_render_window);
			void handleCell(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void handleGameOver();
			void generateRandomMineNumber();
			void firstCellImplementation(sf::Vector2i _cell_array_pos);
			float getCellSizeWidth();
			float getCellSizeHeight();
			void fillBoard();
			void fillWithMines();
			void setCellValues();
			int cellAroundControl(int _i, int _j);
			void setCellBombValue(int _i, int _j, int _bomb_count);
			void onCellButtonClicked(sf::Vector2i _cell_array_pos, UI::MouseButtonType _button_type);
			void openCell(sf::Vector2i _cell_array_pos);
			void markFlagCell(sf::Vector2i _cell_array_pos);
			void openEmptyCells(int i, int j);
			void openBombCells();
			bool checkWin();
			bool controlAllCellsOpen();
			void openFlagCells();
			BoardState setBoardState(BoardState _new_board_state);
			BoardState getBoardState();

	};
}