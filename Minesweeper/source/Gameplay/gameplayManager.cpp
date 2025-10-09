#include "../../header/UI/GameplayUI/GameplayUI.h"
#include "../../header/Gameplay/gameplayManager.h"
#include "../../header/Gameplay/board.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Time/TimeManager.h"

namespace Gameplay
{
	void GameplayManager::initialize()
	{
		initializeVariables();
	}

	void GameplayManager::initializeVariables()
	{
		_board = new Board(this);
		_gameplayUI = new UI::GameplayUI(this);
		remainingTime = maxLevelDuration;
		previousSecond = maxLevelDuration + 1;
	}

	void GameplayManager::update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window)
	{
		handleGameplay(_event_manager, _game_window);
	}

	void GameplayManager::handleGameplay(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		updateRemainingTime();
		_gameplayUI->update(getRemainingTime(previousSecond), _board->getMineCount(), _event_manager, _game_window);
		if (_gameResult == CONTINUE)
		{
			_board->update(_event_manager, _game_window);
		}
	}

	void GameplayManager::render(sf::RenderWindow &_game_window)
	{
		_board->render(_game_window);
		_gameplayUI->render(_game_window);
	}

	GameResult GameplayManager::setGameResult(GameResult _newGameResult)
	{
		return _gameResult = _newGameResult;
	}

	GameResult GameplayManager::getGameResult()
	{
		return _gameResult;
	}

	void GameplayManager::updateRemainingTime()
	{
		remainingTime -= Time::TimeManager::getDeltaTime(); // static function
		
		int currentSecond = static_cast<int>(remainingTime);
		if (currentSecond != previousSecond)
		{
			if (currentSecond >= 0)
			{
				std::cout << currentSecond;
			}
			previousSecond = currentSecond;
		}

		if (remainingTime <= 0)
		{
			remainingTime = 0;
			_gameResult = LOST;
		}
	}

	int GameplayManager::getRemainingTime(int _previous_time)
	{
		return _previous_time;
	}

	void GameplayManager::resetGame()
	{
		_board->reset(this);
		_gameResult = GameResult::CONTINUE;
		Time::TimeManager::initialize();
		remainingTime = maxLevelDuration;
	}
}