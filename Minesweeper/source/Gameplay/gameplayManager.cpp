#include "../../header/Gameplay/gameplayManager.h"
#include "../../header/Gameplay/board.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Time/TimeManager.h"
#include "../../header/UI/GameplayUI/MainMenu.h"
#include "../../header/GameLoop/GameLoop.h"
#include "../../header/UI/GameplayUI/GameplayUI.h"

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
		_mainUI = new UI::MainMenuManager(this);
		remainingTime = maxLevelDuration;
		previousSecond = maxLevelDuration + 1;
	}

	void GameplayManager::update(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		updateRemainingTime();
		if (_gameResult == CONTINUE || _gameResult == WIN || _gameResult == LOST)
		{
			_gameplayUI->update(getRemainingTime(previousSecond), _board->getMineCount(), _event_manager, _game_window);
			_board->update(_event_manager, _game_window);
		}
		if (_gameResult == START)
		{
			_mainUI->update(_game_window, _event_manager);
		}
	}

	void GameplayManager::render(sf::RenderWindow& _game_window)
	{
		_board->render(_game_window);
		if (_gameResult == CONTINUE || _gameResult == WIN || _gameResult == LOST)
		{
			_gameplayUI->render(_game_window);
		}
		if (_gameResult == START)
		{
			_mainUI->render(_game_window);
		}
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

	void GameplayManager::play()
	{
		_gameResult = GameResult::CONTINUE;
	}

	void GameplayManager::quit()
	{
		GameLoop::setGameState(GameState::EXIT);
	}
}