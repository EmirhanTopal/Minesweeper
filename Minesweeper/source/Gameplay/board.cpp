#include "../../header/Gameplay/board.h"

namespace Gameplay_N
{
	Board::Board()
	{
		initialize();
	}

	void Board::initialize()
	{
		initTexture();
		initVariables();
	}

	void Board::initTexture()
	{
		if (!boardTexture.loadFromFile(boardTexturePath))
			std::cout << "file could not be opened";
		else
			boardSprite.setTexture(boardTexture);

		if (!backgroundTexture.loadFromFile(backgroundTexturePath))
			std::cout << "file could not be opened";
		else
			backgroundSprite.setTexture(backgroundTexture);

	}

	void Board::initVariables()
	{
		boardSprite.setPosition(board_pos_x, board_pos_y);
		boardSprite.setScale(boardWidth / boardTexture.getSize().x,
			boardHeight / boardTexture.getSize().y);

		backgroundSprite.setPosition(background_pos_x, background_pos_y);
		backgroundSprite.setScale(2.0f, 1.2f);
	}

	void Board::render(sf::RenderWindow* _render_window)
	{
		_render_window->draw(backgroundSprite);
		_render_window->draw(boardSprite);
	}
}