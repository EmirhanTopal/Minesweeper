#include "../../header/Gameplay/board.h"

namespace Gameplay
{
	Board::Board()
	{
		initialize();
	}

	void Board::initialize()
	{
		initVariables();
	}

	void Board::initVariables()
	{
		if (!boardTexture.loadFromFile(boardTexturePath))
			std::cout << "file could not be opened";
		else
			boardSprite.setTexture(boardTexture);

		if (!backgroundTexture.loadFromFile(backgroundTexturePath))
			std::cout << "file could not be opened";
		else
			backgroundSprite.setTexture(backgroundTexture);

		boardSprite.setPosition(board_pos_x, board_pos_y);

		//background
		backgroundSprite.setPosition(background_pos_x, background_pos_y);
		backgroundSprite.setScale(2.0f, 1.2f);

		//cell
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j] = new Cell(getCellSizeHeight(), getCellSizeWidth(), 
					sf::Vector2f(Cell::getCellLeftValue() + j * getCellSizeHeight() + j, Cell::getCellTopValue() + i * getCellSizeHeight()));
			}
		}
	}

	void Board::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(backgroundSprite);
		_game_window.draw(boardSprite);
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j]->render(_game_window);
			}
		}
	}

	float Board::getCellSizeWidth()
	{
		return (boardPlayableWidth / numOfColumns);

	}

	float Board::getCellSizeHeight()
	{
		return (boardPlayableHeight / numOfRows);

	}
}