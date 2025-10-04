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
		//e�er cellbutton null de�ilse button �zerinden render yap ��nk� zaten oradaki sprite � render edece�iz
		//her cell in farkl� �zellikleri var bomba olabilir say� olabilir fakat hepsi clickable en ba�ta bu y�zden button �zerinden �a��r�yoruz
		if (cellButton)
			cellButton->render(_game_window);
	}
}