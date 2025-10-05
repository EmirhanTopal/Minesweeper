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
					sf::Vector2f(Cell::getCellLeftValue() + j * getCellSizeHeight() + j, Cell::getCellTopValue() + i * getCellSizeHeight()));
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
		switch (_bomb_count)
		{
		case (1):
			cellArray[i][j]->changeCellType(CellType::ONE);
			break;
		case (2):
			cellArray[i][j]->changeCellType(CellType::TWO);
			break;
		case (3):
			cellArray[i][j]->changeCellType(CellType::THREE);
			break;
		case (4):
			cellArray[i][j]->changeCellType(CellType::FOUR);
			break;
		case (5):
			cellArray[i][j]->changeCellType(CellType::FIVE);
			break;
		case (6):
			cellArray[i][j]->changeCellType(CellType::SIX);
			break;
		case (7):
			cellArray[i][j]->changeCellType(CellType::SEVEN);
			break;
		case (8):
			cellArray[i][j]->changeCellType(CellType::EIGHT);
			break;
		default:
			break;
		}
	}
}