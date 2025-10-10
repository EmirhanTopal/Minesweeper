#include "../../header/Gameplay/board.h"
#include "../../header/Gameplay/gameplayManager.h"

namespace Gameplay
{
	Board::Board(GameplayManager* _gameplayManager)
	{
		initialize(_gameplayManager);
	}

	void Board::initialize(GameplayManager* _gameplayManager)
	{
		initVariables(_gameplayManager);
	}


	void Board::initVariables(GameplayManager* _gameplayManager)
	{
		//Board
		if (!boardTexture.loadFromFile(boardTexturePath))
			std::cout << "file could not be opened";
		else
			boardSprite.setTexture(boardTexture);
		boardSprite.setPosition(board_pos_x, board_pos_y);

		if (!backgroundTexture.loadFromFile(backgroundTexturePath))
			std::cout << "file could not be opened";
		else
			backgroundSprite.setTexture(backgroundTexture);
		//background
		backgroundSprite.setPosition(background_pos_x, background_pos_y);

		_boardState = BoardState::FIRSTCELL;

		//cell
		fillBoard();
		firstCellVector.x = -1;
		firstCellVector.y = -1;

		//mine
		generateRandomMineNumber();

		//gameplay manager
		this->_gameplayManager = _gameplayManager;
	}

	void Board::update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window)
	{
		handleCell(_event_manager, _game_window);
		handleGameOver();

	}

	void Board::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(backgroundSprite);
		if (_gameplayManager->getGameResult() == GameResult::CONTINUE || _gameplayManager->getGameResult() == GameResult::LOST || _gameplayManager->getGameResult() == GameResult::WIN)
		{
			_game_window.draw(boardSprite);
			for (size_t i = 0; i < numOfRows; i++)
			{
				for (size_t j = 0; j < numOfColumns; j++)
				{
					cellArray[i][j]->render(_game_window);
				}
			}
		}
	}

	void Board::handleCell(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j]->update(_event_manager, _game_window);
			}
		}
	}

	void Board::handleGameOver()
	{
		if (_gameplayManager->getGameResult() != GameResult::LOST)
		{
			if (checkWin())
			{
				_gameplayManager->setGameResult(GameResult::WIN);
				std::cout << "win";
			}
		}
	}

	void Board::generateRandomMineNumber()
	{
<<<<<<< Updated upstream
		//Board
		if (!boardTexture.loadFromFile(boardTexturePath))
			std::cout << "file could not be opened";
		else
			boardSprite.setTexture(boardTexture);

		if (!backgroundTexture.loadFromFile(backgroundTexturePath))
			std::cout << "file could not be opened";
		else
			backgroundSprite.setTexture(backgroundTexture);

		boardSprite.setPosition(board_pos_x, board_pos_y);

		_boardState = BoardState::FIRSTCELL;

		//background
		backgroundSprite.setPosition(background_pos_x, background_pos_y);
		backgroundSprite.setScale(2.0f, 1.2f);

		//cell
		fillBoard();
		

		this->_gameplayManager = _gameplayManager;
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
=======
		std::random_device rd;
		std::default_random_engine engine(rd());
		std::uniform_int_distribution<int> mines_count_dist(randMinBombValue, randMaxBombValue);
		minesCount = mines_count_dist(engine);
>>>>>>> Stashed changes
	}

	void Board::firstCellImplementation(sf::Vector2i _cell_array_pos)
	{
		if (firstCellVector.x == -1 && firstCellVector.y == -1 && getBoardState() == BoardState::FIRSTCELL)
		{
			firstCellVector.x = _cell_array_pos.x;
			firstCellVector.y = _cell_array_pos.y;
			std::cout << "sa";
			setBoardState(BoardState::PLAYING);
			fillWithMines();
			setCellValues();
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
		std::uniform_int_distribution<int> mines_count_dist(randMinBombValue, randMaxBombValue);
		int mines_count = mines_count_dist(engine);
		while (mines_count > 0)
		{
			std::uniform_int_distribution<int> row_dist(0, numOfRows - 1);
			std::uniform_int_distribution<int> column_dist(0, numOfColumns - 1);
			int row_dist_pos = row_dist(engine);
			int column_dist_pos = column_dist(engine);
			std::cout << "A" << std::endl;
			for (size_t i = 0; i < numOfRows; i++)
			{
				for (size_t j = 0; j < numOfColumns; j++)
				{
					if (i == firstCellVector.x && j == firstCellVector.y)
					{
						std::cout << "koymaya çalýþtým ama geçtim";
						continue;
					}
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
		{
			firstCellImplementation(_cell_array_pos);
			if (getBoardState() == BoardState::PLAYING)
			{
				openCell(_cell_array_pos);
			}
		}

		else if (_button_type == UI::MouseButtonType::RIGHT_CLICK)
		{
			markFlagCell(_cell_array_pos);
			if (cellArray[_cell_array_pos.x][_cell_array_pos.y]->getCurrentCellState() == CellState::HIDE)
				flagCellCount--;
			else
				flagCellCount++;
		}
	}

	void Board::openCell(sf::Vector2i _cell_array_pos)
	{
		if (cellArray[_cell_array_pos.x][_cell_array_pos.y]->getCurrentCellState() == CellState::OPEN)
			return;
		switch (cellArray[_cell_array_pos.x][_cell_array_pos.y]->getCellType())
		{
			case(CellType::EMPTY):
				openEmptyCells(_cell_array_pos.x, _cell_array_pos.y);
				break;
			case(CellType::BOMB):
				openBombCells();
				_gameplayManager->setGameResult(GameResult::LOST);
				break;
			default:
				cellArray[_cell_array_pos.x][_cell_array_pos.y]->open();
				break;
		}

	}

	void Board::openEmptyCells(int i, int j)
	{
		cellArray[i][j]->open();
		if (cellArray[i][j]->getCellType() != CellType::BOMB)
		{
			if (j > 0 && cellArray[i][j - 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i, j - 1));
			}
			if (j < (numOfColumns - 1) && cellArray[i][j + 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i, j + 1));
			}
			if (i > 0 && j > 0 && cellArray[i - 1][j - 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i - 1, j - 1));
			}
			if (i > 0 && cellArray[i - 1][j]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i - 1, j));
			}
			if (i > 0 && j < (numOfColumns - 1) && cellArray[i - 1][j + 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i - 1, j + 1));
			}
			if (i < (numOfRows - 1) && j > 0 && cellArray[i + 1][j - 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i + 1, j - 1));;
			}
			if (i < (numOfRows - 1) && cellArray[i + 1][j]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i + 1, j));
			}
			if (i < (numOfRows - 1) && j < (numOfColumns - 1) && cellArray[i + 1][j + 1]->getCellType() != CellType::BOMB)
			{
				openCell(sf::Vector2i(i + 1, j + 1));
			}
		}
	}

	void Board::openBombCells()
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				if (cellArray[i][j]->getCellType() == CellType::BOMB && cellArray[i][j]->getCurrentCellState() != CellState::OPEN)
				{
					cellArray[i][j]->open();
				}
			}
		}
	}

	void Board::markFlagCell(sf::Vector2i _cell_array_pos)
	{
		cellArray[_cell_array_pos.x][_cell_array_pos.y]->putFlag();
	}

	bool Board::checkWin()
	{
		if (controlAllCellsOpen())
		{
			openFlagCells();
			return true;
		}
		return false;
	}

	bool Board::controlAllCellsOpen()
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				if (cellArray[i][j]->getCellType() == CellType::BOMB && cellArray[i][j]->getCurrentCellState() == CellState::HIDE)
				{
					continue;
				}
				else if (cellArray[i][j]->getCurrentCellState() == CellState::HIDE || cellArray[i][j]->getCurrentCellState() == CellState::FLAG)
				{
					return false;
				}
			}
		}
		return true;
	}

	void Board::openFlagCells()
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				if (cellArray[i][j]->getCellType() == CellType::BOMB)
				{
					cellArray[i][j]->changeCurrentCellState(CellState::FLAG);
				}
			}
		}
	}

	BoardState Board::setBoardState(BoardState _new_board_state)
	{
		return _boardState = _new_board_state;
	}

	BoardState Board::getBoardState()
	{
		return _boardState;
	}
<<<<<<< Updated upstream
=======

	void Board::reset(GameplayManager* _gameplayManager)
	{
		for (size_t i = 0; i < numOfRows; i++)
		{
			for (size_t j = 0; j < numOfColumns; j++)
			{
				cellArray[i][j]->reset();
			}
		}
		generateRandomMineNumber();
		_boardState = BoardState::FIRSTCELL;
		firstCellVector.x = -1;
		firstCellVector.y = -1;
	}
>>>>>>> Stashed changes
}