#pragma once
#include <SFML/Graphics.hpp>
#include "../UIElements/Button/Button.h"
#include "../../Gameplay/gameplayManager.h"
#include "../../header/Event/EventPollingManager.h"


namespace UI
{
	class GameplayUI
	{
		private:
			sf::Font mineFont;
			sf::Text mineText;
			std::string mineInitialText = "00";

			float mineTextPosX;
			float mineTextPosY;

			sf::Font timerFont;
			sf::Text timerText;
			std::string timerInitialText = "000";

			float timerTextPosX;
			float timerTextPosY;

			int textSize = 55;
			std::string mineTimerFontPath = "assets/fonts/bubbleBobble.ttf";

			UI::Button* restartButton;
			std::string restartButtonPath = "assets/textures/ResetButton.png";

		public:
			GameplayUI(Gameplay::GameplayManager *gameplayManager);
			void initialize(Gameplay::GameplayManager *gameplayManager);
			void initializeVariables(Gameplay::GameplayManager *gameplayManager);
			void render(sf::RenderWindow& _game_window);
			void update(int _remain_time, int _remain_mine, Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void createMineCountUI();
			void createTimerUI();
			std::string updateTimerUI(int _remain_time);
			std::string updateMineUI(int _remain_mine);
			void initalizeResetButton();
			void registerRestartButtonCallBack(Gameplay::GameplayManager* gameplayManager);
			void restartButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager *gameplayManager);
	};
}