#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"



namespace Gameplay
{
	enum CellType
	{
		EMPTY,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		BOMB,
	};

	enum CellState
	{
		HIDE,
		FLAG,
		OPEN,
	};

	class Board;

	class Cell
	{
		private:
			const int tileSize = 128;
			const int sliceCount = 12;
			const static int cell_left_default = 570; // 575 - 1304
			const static int cell_top_default = 165; // 165 - 894
			const std::string cellTexturePath = "assets/textures/PokemonCells.png";
			CellState currentCellState = HIDE;
			CellType cellType = EMPTY;
			sf::Vector2f position;
			UI::Button* cellButton;
			Board *board;
			bool isOpen;
			sf::Vector2i rowAndColumn{ -1, -1};

		public:
			Cell(float _width, float _height, sf::Vector2f _position, Board *board, sf::Vector2i _arr_pos);
			void initialize(float _width, float _height, sf::Vector2f _position, Board* board, sf::Vector2i _arr_pos);
			void update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window);
			void render(sf::RenderWindow &_game_window);
			void changeCurrentCellState(CellState _change_cell_state);
			CellState getCurrentCellState();
			void changeCellType(CellType _change_cell_type);
			void setCellTexture();
			CellType getCellType();
			static int getCellLeftValue();
			static int getCellTopValue();
			sf::Vector2f getCellPos();
			sf::Vector2i setRowAndColumnArray(int _row, int _column);
			sf::Vector2i getRowAndColumnArray();
			void registerCellButtonCallback();
			void cellButtonCallback(UI::MouseButtonType button_type);
			bool canOpenCell();
			void open();
			void putFlag();
			
	};
}