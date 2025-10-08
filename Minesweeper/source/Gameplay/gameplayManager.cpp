#include "../../header/Gameplay/gameplayManager.h"
#include "../../header/Gameplay/board.h"
#include "../../header/Event/EventPollingManager.h"
namespace Gameplay
{
	void GameplayManager::initialize()
	{
		_board = new Board(this);
	}

	void GameplayManager::update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window)
	{
		if (_gameResult == CONTINUE)
		{
			_board->update(_event_manager, _game_window);
		}
	}

	void GameplayManager::render(sf::RenderWindow& _game_window)
	{
		_board->render(_game_window);
	}

	GameResult GameplayManager::setGameResult(GameResult _newGameResult)
	{
		return _gameResult = _newGameResult;
	}

	GameResult GameplayManager::getGameResult()
	{
		return _gameResult;
	}
}