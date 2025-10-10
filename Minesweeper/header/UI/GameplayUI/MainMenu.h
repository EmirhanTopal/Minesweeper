#pragma once
#include <SFML/Graphics.hpp>
#include "../UIElements/Button/Button.h"
#include "../../Gameplay/gameplayManager.h"

namespace UI
{
	class MainMenuManager
	{
		private:
			std::string playTexturePath = "assets/textures/pokemonPlayy.png";
			float playPosX = 350.0f;
			float playPosY = 420.0f;
			UI::Button* playButton;

			std::string quitTexturePath = "assets/textures/pokemonQuitt.png";
			float quitPosX = 1350.0f;
			float quitPosY = 420.0f;
			UI::Button* quitButton;

		public:
			MainMenuManager(Gameplay::GameplayManager* gameplayManager);
			void initialize(Gameplay::GameplayManager* gameplayManager);
			void initalizeVariables(Gameplay::GameplayManager* gameplayManager);
			void update(sf::RenderWindow& _game_window, Event::EventPollingManager _event_manager);
			void render(sf::RenderWindow &_game_window);
			void createButtons();
			void registerPlayButtonCallBack(Gameplay::GameplayManager* gameplayManager);
			void playButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager* gameplayManager);
			void registerQuitButtonCallBack(Gameplay::GameplayManager* gameplayManager);
			void quitButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager* gameplayManager);
	};
}