#include "../../header/Gameplay/gameplayManager.h"
#include "../../header/Gameplay/board.h"
#include "../../header/Event/EventPollingManager.h"
namespace Gameplay
{
	void GameplayManager::initialize()
	{
		_board = new Board();
	}

	void GameplayManager::update(Event::EventPollingManager &_event_manager, sf::RenderWindow &_game_window)
	{
		_board->update(_event_manager, _game_window);
	}

	void GameplayManager::render(sf::RenderWindow& _game_window)
	{
		_board->render(_game_window);
	}
}