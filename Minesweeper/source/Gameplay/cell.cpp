#include "../../header/Gameplay/Cell.h"
#include "../../header/UI/UIElements/Button/Button.h",

namespace Gameplay
{
	Cell::Cell(float _width, float _height)
	{
		initialize(_width, _height);
	}

	void Cell::initialize(float _width, float _height)
	{
		// cell position ayarla ve sonras�nda bu bir clickable oldu�u i�in button �a��r
		//button init edilen path pos width height al�r ve sprite � buna g�re ayarlar
		sf::Vector2f cell_pos = getCellPos();
		cellButton = new UI::Button(cellTexturePath, cell_pos, _width, _height);
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

	sf::Vector2f Cell::getCellPos() const
	{
		return sf::Vector2f(cell_left_default, cell_top_default);
	}

}