#pragma once
#include "board.h"
#include "../UI/UIElements/Button/Button.h"

<<<<<<< Updated upstream
=======
namespace UI
{
	class GameplayUI;
	class MainMenuManager;
}

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
			GameResult _gameResult = CONTINUE;
=======
			UI::GameplayUI *_gameplayUI;
			UI::MainMenuManager* _mainMenuManager;
			GameResult _gameResult = START;
>>>>>>> Stashed changes
=======
			UI::GameplayUI *_gameplayUI;
			UI::MainMenuManager* _mainMenuManager;
			GameResult _gameResult = START;
>>>>>>> Stashed changes
=======
			UI::GameplayUI *_gameplayUI;
			UI::MainMenuManager* _mainMenuManager;
			GameResult _gameResult = START;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
			int getRemainingTime(int _previous_time);
			void resetGame();
			void play();
			void quit();
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
	};
}