#pragma once
#include "../../header/Gameplay/Cell.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gameplay
{
	class Board
	{
		private:
			//gameplay board
			sf::Texture boardTexture;
			sf::Sprite boardSprite;
			std::string boardTexturePath = "assets/textures/PokemonBoard.png";
			float board_pos_x = 480.0f;
			float board_pos_y = 0.0f;
			const float boardWidth = 960.f;
			const float boardHeight = 1080.f;

			//background
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;
			std::string backgroundTexturePath = "assets/textures/pokemon_bg.png";
			float background_pos_x = 0.0f;
			float background_pos_y = 0.0f;

			//cell
			Cell *cell;

		public:
			Board();
			void initialize();
			void initVariables();
			void render(sf::RenderWindow &_render_window);
	};
}