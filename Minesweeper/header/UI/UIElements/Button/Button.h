#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	enum class MouseButtonType
	{
		LEFT_CLICK,
		RIGHT_CLICK
	};

	class Button
	{
		private:
			sf::Texture buttonTexture;
			sf::Sprite buttonSprite;


		public:
			Button(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void initialize(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void initVariables(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void render(sf::RenderWindow &_game_window);
			void setTextureRect(const sf::IntRect &_button_rect);
	};
}