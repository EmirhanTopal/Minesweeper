#pragma once
#include "board.h"
#include "../UI/UIElements/Button/Button.h"

namespace UI
{
	class GameplayUI;
	class MainMenuManager;
}

namespace Gameplay
{
	enum GameResult
	{
		START,
		WIN,
		LOST,
		CONTINUE
	};
	
	class GameplayManager
	{
		private:
			Board *_board;
			GameResult _gameResult = START;
			UI::GameplayUI *_gameplayUI;
			UI::MainMenuManager* _mainUI;
			float maxLevelDuration = 150.0f;
			float remainingTime;
			int previousSecond;

		public:
			void initialize();
			void initializeVariables();
			void update(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void handleGameplay(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void render(sf::RenderWindow& _game_window);
			GameResult setGameResult(GameResult _newGameResult);
			GameResult getGameResult();
			void updateRemainingTime();
			int getRemainingTime(int _previous_time);
			void resetGame();
			void play();
			void quit();
	};
}