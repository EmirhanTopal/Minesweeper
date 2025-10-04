#include "../../header/UI/UIElements/Button/Button.h"
#include <iostream>

namespace UI
{
	Button::Button(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height)
	{
		initialize(_button_texture_path, _position, _width, _height);
	}

	void Button::initialize(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height)
	{
		initVariables(_button_texture_path, _position, _width, _height);
	}

	void Button::initVariables(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height)
	{
		if (!buttonTexture.loadFromFile(_button_texture_path))
		{
			std::cout << "file could not be opened";
			return;
		}
		buttonSprite.setTexture(buttonTexture);
		buttonSprite.setPosition(_position);
		buttonSprite.setScale(_width / 128, _height / 128);
	}

	void Button::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(buttonSprite);
	}

	void Button::setTextureRect(const sf::IntRect& _button_rect)
	{
		buttonSprite.setTextureRect(_button_rect);
	}

}