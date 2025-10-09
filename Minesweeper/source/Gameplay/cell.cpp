#include "../../header/Gameplay/Cell.h"
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Gameplay/board.h"

namespace Gameplay
{
	Cell::Cell(float _width, float _height, sf::Vector2f _position, Board* _board, sf::Vector2i _arr_pos)
	{
		initialize(_width, _height, _position, _board, _arr_pos);
	}

	void Cell::initialize(float _width, float _height, sf::Vector2f _position, Board* _board, sf::Vector2i _arr_pos)
	{
		this->position = _position;
		// cell position ayarla ve sonrasýnda bu bir clickable olduðu için button çaðýr
		//button init edilen path pos width height alýr ve sprite ý buna göre ayarlar
		this->board = _board;
		rowAndColumn = _arr_pos;
		cellButton = new UI::Button(cellTexturePath, position, _width, _height);
		registerCellButtonCallback();
	}

	void Cell::cellButtonCallback(UI::MouseButtonType _button_type)
	{
		board->onCellButtonClicked(getRowAndColumnArray(), _button_type);
	}

	// lambda function explaning

	/*void A(UI::MouseButtonType _button_type)
	{
		std::cout << "sa";
	}*/

	void Cell::registerCellButtonCallback()
	{
		//lambda function - *önemli*
		//cellButton->registerCallBackFunc(A); // ayný þey
		cellButton->registerCallBackFunc([this](UI::MouseButtonType _button_type)
		{
			cellButtonCallback(_button_type);
		});

	}

	void Cell::update(Event::EventPollingManager& _event_manager, sf::RenderWindow &_game_window)
	{
		if (cellButton)
		{
			cellButton->detectMouseClick(_event_manager, _game_window);
		}
	}

	void Cell::render(sf::RenderWindow &_game_window)
	{
		setCellTexture();
		//eðer cellbutton null deðilse button üzerinden render yap çünkü zaten oradaki sprite ý render edeceðiz
		//her cell in farklý özellikleri var bomba olabilir sayý olabilir fakat hepsi clickable en baþta bu yüzden button üzerinden çaðýrýyoruz
		if (cellButton)
			cellButton->render(_game_window);
	}

	void Cell::changeCurrentCellState(CellState _change_cell_state)
	{
		currentCellState = _change_cell_state;
	}

	CellState Cell::getCurrentCellState()
	{
		return currentCellState;
	}

	void Cell::changeCellType(CellType _change_cell_type)
	{
		cellType = _change_cell_type;
	}

	CellType Cell::getCellType()
	{
		return cellType;
	}

	void Cell::setCellTexture()
	{
		int cellTypeIndexByTexture = static_cast<int>(cellType);
		switch (currentCellState)
		{
			case Gameplay::HIDE:
				cellButton->setTextureRect(sf::IntRect(tileSize * 10, 0, tileSize, tileSize));
				break;
			case Gameplay::FLAG:
				cellButton->setTextureRect(sf::IntRect(tileSize * 11, 0, tileSize, tileSize));
				break;
			case Gameplay::OPEN:
				cellButton->setTextureRect(sf::IntRect(cellTypeIndexByTexture * tileSize, 0, tileSize, tileSize));
				break;
			default:
				break;
		}
	}

	sf::Vector2f Cell::getCellPos()
	{
		return sf::Vector2f(position.x, position.y);
	}

	int Cell::getCellLeftValue()
	{
		return cell_left_default;
	}

	int Cell::getCellTopValue()
	{
		return cell_top_default;
	}

	sf::Vector2i Cell::setRowAndColumnArray(int _row, int _column)
	{
		rowAndColumn.x = _row;
		rowAndColumn.y = _column;
		return rowAndColumn;
	}

	sf::Vector2i Cell::getRowAndColumnArray()
	{
		return rowAndColumn;
	}

	bool Cell::canOpenCell()
	{
		if (currentCellState == CellState::HIDE)
		{
			return true;
		}
		return false;
	}

	void Cell::open()
	{
		if (canOpenCell())
			changeCurrentCellState(CellState::OPEN);
	}

	void Cell::putFlag()
	{
		if (currentCellState == CellState::HIDE)
			changeCurrentCellState(CellState::FLAG);
		else if (currentCellState == CellState::FLAG)
			changeCurrentCellState(CellState::HIDE);
	}

	

}