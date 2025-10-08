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

	void Board::update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window)
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j]->update(_event_manager, _game_window);
			}
		}
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
		fillBoard();
		fillWithMines();
		setCellValues();
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

	void Board::fillBoard()
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j] = new Cell(getCellSizeHeight(), getCellSizeWidth(),
					sf::Vector2f(Cell::getCellLeftValue() + j * getCellSizeHeight() + j, Cell::getCellTopValue() + i * getCellSizeHeight()), this, sf::Vector2i(i,j));
			}
		}
	}

	void Board::fillWithMines()
	{
		std::random_device rd;
		std::default_random_engine engine(rd());
		std::uniform_int_distribution<int> mines_count_dist(10, 20);
		int mines_count = mines_count_dist(engine);
		while (mines_count > 0)
		{
			std::uniform_int_distribution<int> row_dist(0, numOfRows - 1);
			std::uniform_int_distribution<int> column_dist(0, numOfColumns - 1);
			int row_dist_pos = row_dist(engine);
			int column_dist_pos = column_dist(engine);
			for (size_t i = 0; i < numOfRows; i++)
			{
				for (size_t j = 0; j < numOfColumns; j++)
				{
					if (i == row_dist_pos && j == column_dist_pos && cellArray[i][j]->getCellType() != CellType::BOMB)
					{
						cellArray[i][j]->changeCellType(CellType::BOMB);
						mines_count--;
					}
				}
			}
		}
	}

	void Board::setCellValues()
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				int bomb_count = 0;
				bomb_count = cellAroundControl(i, j);
				setCellBombValue(i, j, bomb_count);
			}
		}
	}

	int Board::cellAroundControl(int i, int j)
	{
		int bomb_count = 0;
		if (cellArray[i][j]->getCellType() != CellType::BOMB)
		{
			if (j > 0 && cellArray[i][j - 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (j < (numOfColumns - 1) && cellArray[i][j + 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i > 0 && j > 0 && cellArray[i - 1][j - 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i > 0 && cellArray[i - 1][j]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i > 0 && j < (numOfColumns - 1) && cellArray[i - 1][j + 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i < (numOfRows - 1) && j > 0 && cellArray[i + 1][j - 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i < (numOfRows - 1) && cellArray[i + 1][j]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
			if (i < (numOfRows - 1) && j < (numOfColumns - 1) && cellArray[i + 1][j + 1]->getCellType() == CellType::BOMB)
			{
				bomb_count++;
			}
		}
		return bomb_count;
	}

	void Board::setCellBombValue(int i, int j, int _bomb_count)
	{
		if (_bomb_count != 0)
		{
			cellArray[i][j]->changeCellType(static_cast<CellType>(_bomb_count));
		}
	}

	void Board::onCellButtonClicked(sf::Vector2i _cell_array_pos, UI::MouseButtonType _button_type)
	{
		if (_button_type == UI::MouseButtonType::LEFT_CLICK) 
			openCell(_cell_array_pos);

		else if (_button_type == UI::MouseButtonType::RIGHT_CLICK)
		{
			flagCell(_cell_array_pos);
			if (cellArray[_cell_array_pos.x][_cell_array_pos.y]->getCurrentCellState() == CellState::HIDE)
				flagCellCount--;
			else
				flagCellCount++;

			std::cout << flagCellCount;
		}
	}

	void Board::openCell(sf::Vector2i _cell_array_pos)
	{
		cellArray[_cell_array_pos.x][_cell_array_pos.y]->open();
	}

	void Board::flagCell(sf::Vector2i _cell_array_pos)
	{
		cellArray[_cell_array_pos.x][_cell_array_pos.y]->putFlag();
	}
}