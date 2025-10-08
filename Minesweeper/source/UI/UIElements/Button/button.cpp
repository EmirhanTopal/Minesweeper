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

	bool Button::isMouseOnSprite(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		sf::Vector2i mouse_pos = _event_manager.getMousePosition();
		return buttonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos));
	}

	void Button::detectMouseClick(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		if (_event_manager.pressedLeftMouseButton() && isMouseOnSprite(_event_manager, _game_window))
			callBackFunc(MouseButtonType::LEFT_CLICK); // callBackFunc þimdi paramteresi ** leftClick ** olarak atanan dinamik bir fonksiyon onu o paramterle ile her yerde kullanabiliriz

		else if (_event_manager.pressedRightMouseButton() && isMouseOnSprite(_event_manager, _game_window))
			callBackFunc(MouseButtonType::RIGHT_CLICK); // callBackFunc þimdi paramteresi ** rightClick ** olarak atanan dinamik bir fonksiyon onu o paramterle ile her yerde kullanabiliriz
	}

	void Button::registerCallBackFunc(CallBackFunc _button_call_back)
	{
		callBackFunc = _button_call_back;
	}
}