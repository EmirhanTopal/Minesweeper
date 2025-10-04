#include "../../header/Gameplay/Cell.h"
#include "../../header/UI/UIElements/Button/Button.h",

namespace Gameplay
{
	Cell::Cell(sf::Vector2f _position, float _width, float _height)
	{
		initialize(_position, _width, _height);
	}

	void Cell::initialize(sf::Vector2f _position, float _width, float _height)
	{
		this->position = _position; // cell position ayarla ve sonras�nda bu bir clickable oldu�u i�in button �a��r
		//button init edilen path pos width height al�r ve sprite � buna g�re ayarlar
		cellButton = new UI::Button(cellTexturePath, position, _width, _height);
	}

	void Cell::render(sf::RenderWindow &_game_window)
	{
		setCellTexture();
		//e�er cellbutton null de�ilse button �zerinden render yap ��nk� zaten oradaki sprite � render edece�iz
		//her cell in farkl� �zellikleri var bomba olabilir say� olabilir fakat hepsi clickable en ba�ta bu y�zden button �zerinden �a��r�yoruz
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
				cellButton->setTextureRect(sf::IntRect(128 * 10, 0, 128, 128));
				break;
			case Gameplay::FLAG:
				cellButton->setTextureRect(sf::IntRect(128 * 11, 0, 128, 128));
				break;
			case Gameplay::OPEN:
				cellButton->setTextureRect(sf::IntRect(cellTypeIndexByTexture * 128, 0, 128, 128));
				break;
			default:
				break;
		}
	}

}