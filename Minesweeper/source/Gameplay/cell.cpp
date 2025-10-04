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
		this->position = _position; // cell position ayarla ve sonrasýnda bu bir clickable olduðu için button çaðýr
		//button init edilen path pos width height alýr ve sprite ý buna göre ayarlar
		cellButton = new UI::Button(cellTexturePath, position, _width, _height);
	}

	void Cell::render(sf::RenderWindow &_game_window)
	{
		//eðer cellbutton null deðilse button üzerinden render yap çünkü zaten oradaki sprite ý render edeceðiz
		//her cell in farklý özellikleri var bomba olabilir sayý olabilir fakat hepsi clickable en baþta bu yüzden button üzerinden çaðýrýyoruz
		if (cellButton)
			cellButton->render(_game_window);
	}
}