#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "../../header/Event/EventPollingManager.h"

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
			bool isOpen = false;

			using CallBackFunc = std::function<void(MouseButtonType)>;
			CallBackFunc callBackFunc = nullptr;

		public:

			Button(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void initialize(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void initVariables(std::string _button_texture_path, sf::Vector2f _position, float _width, float _height);
			void render(sf::RenderWindow &_game_window);
			void setTextureRect(const sf::IntRect &_button_rect);
			bool isMouseOnSprite(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void detectMouseClick(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void registerCallBackFunc(CallBackFunc _button_call_back);
	};
}