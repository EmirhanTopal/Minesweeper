#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElements/Button/Button.h"

namespace Gameplay
{
	class Cell
	{
		private:
			const int tileSize = 128;
			const int sliceCount = 12;
			const std::string cellTexturePath = "assets/textures/cells.jpeg";
			sf::Vector2f position;

			UI::Button* cellButton;

		public:
			Cell(sf::Vector2f _position, float _width, float _height);
			void initialize(sf::Vector2f _position, float _width, float _height);
			void render(sf::RenderWindow & _game_window);

	};
}