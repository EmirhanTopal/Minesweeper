#pragma once
#include "board.h"
#include "../UI/UIElements/Button/Button.h"

namespace Gameplay
{
	class GameplayManager
	{
		private:
			Board *_board;
		public:
			void initialize();
			void update(Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window);
			void render(sf::RenderWindow& _game_window);
			void onCellButtonClicked(sf::Vector2i cell_position, UI::MouseButtonType mouse_button_type);
	};
}