#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"

namespace Gameplay
{
	enum class CellType
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

	class Cell
	{
		private:
			const int tileSize = 128;
			const int sliceCount = 12;
			const std::string cellTexturePath = "assets/textures/PokemonCells.png";
			CellState currentCellState = HIDE;
			CellType cellType;
			sf::Vector2f position;

			UI::Button* cellButton;

		public:
			Cell(sf::Vector2f _position, float _width, float _height);
			void initialize(sf::Vector2f _position, float _width, float _height);
			void render(sf::RenderWindow & _game_window);
			void changeCurrentCellState(CellState _change_cell_state);
			CellState getCurrentCellState();
			void changeCellType(CellType _change_cell_type);
			void setCellTexture();
			CellType getCellType();

	};
}