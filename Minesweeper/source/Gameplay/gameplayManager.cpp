#include "../../header/Gameplay/gameplayManager.h"
#include "../../header/Gameplay/board.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Time/TimeManager.h"
#include "../../header/UI/GameplayUI/MainMenu.h"
#include "../../header/GameLoop/GameLoop.h"

namespace Gameplay
{
	void GameplayManager::initialize()
	{
		initializeVariables();
	}

	void GameplayManager::initializeVariables()
	{
		_board = new Board(this);
<<<<<<< Updated upstream
=======
		_gameplayUI = new UI::GameplayUI(this);
		_mainMenuManager = new UI::MainMenuManager(this);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
		_mainMenuManager->update(_game_window, _event_manager);
		_gameplayUI->update(getRemainingTime(previousSecond), _board->getMineCount(), _event_manager, _game_window);
>>>>>>> Stashed changes
		if (_gameResult == CONTINUE)
		{
			_board->update(_event_manager, _game_window);
		}
	}

	void GameplayManager::render(sf::RenderWindow& _game_window)
	{
		_board->render(_game_window);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
		if (_gameResult == GameResult::START)
		{
			_mainMenuManager->render(_game_window);
		}
		if (_gameResult == GameResult::CONTINUE || _gameResult == GameResult::LOST || _gameResult == GameResult::WIN)
		{
			_gameplayUI->render(_game_window);
		}
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======

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
		if (_gameResult != GameResult::CONTINUE)
		{
			GameLoop::setGameState(GameState::EXIT);
		}
	}
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}