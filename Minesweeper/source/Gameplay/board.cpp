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
		//boardSprite.setScale(boardWidth / boardTexture.getSize().x,
			//boardHeight / boardTexture.getSize().y);

		backgroundSprite.setPosition(background_pos_x, background_pos_y);
		backgroundSprite.setScale(2.0f, 1.2f);

		cell = new Cell(getCellOfBoardColumn(), getCellOfBoardRow()); //554 - 1283
	}

	void Board::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(backgroundSprite);
		_game_window.draw(boardSprite);
		cell->render(_game_window);
	}

	float Board::getCellOfBoardRow()
	{
		return (boardPlayableWidth / numOfRows);
	}

	float Board::getCellOfBoardColumn()
	{
		return (boardPlayableHeight / numOfColumns);

	}
}