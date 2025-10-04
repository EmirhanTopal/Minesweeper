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
		buttonSprite.setScale(_width / buttonTexture.getSize().x, _height / buttonTexture.getSize().y);
	}

	void Button::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(buttonSprite);
	}

}