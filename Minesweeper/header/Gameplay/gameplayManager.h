#pragma once
#include "board.h"
#include "../UI/UIElements/Button/Button.h"

namespace Gameplay
{
	enum GameResult
	{
		WIN,
		LOST,
		CONTINUE
	};
	
	class GameplayManager
	{
		private:
			Board *_board;
			GameResult _gameResult = CONTINUE;
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
	};
}