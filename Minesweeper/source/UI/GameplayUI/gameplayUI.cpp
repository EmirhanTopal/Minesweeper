#include "../../header/UI/GameplayUI/GameplayUI.h"
#include <iostream>

namespace UI
{
	GameplayUI::GameplayUI(Gameplay::GameplayManager* gameplayManager)
	{
		initialize(gameplayManager);
	}

	void GameplayUI::initialize(Gameplay::GameplayManager* gameplayManager)
	{
		initializeVariables(gameplayManager);
	}

	void GameplayUI::initializeVariables(Gameplay::GameplayManager* gameplayManager)
	{
		mineTextPosX = 600.0f;
		mineTextPosY = 5.0f;
		timerTextPosX = 1300.0f;
		timerTextPosY = 5.0f;
		createMineCountUI();
		createTimerUI();
		initalizeResetButton();
		registerRestartButtonCallBack(gameplayManager);
	}

	void GameplayUI::render(sf::RenderWindow &_game_window)
	{
		_game_window.draw(mineText);
		_game_window.draw(timerText);
		restartButton->render(_game_window);
	}

	void GameplayUI::update(int _remain_time, int _remain_mine, Event::EventPollingManager& _event_manager, sf::RenderWindow& _game_window)
	{
		restartButton->detectMouseClick(_event_manager, _game_window);
		timerText.setString(updateTimerUI(_remain_time));
		mineText.setString(updateMineUI(_remain_mine));
	}

	void GameplayUI::createMineCountUI()
	{
		if(!mineFont.loadFromFile(mineTimerFontPath))
			std::cerr << "Error loading bubbleBobble font!" << std::endl;
		mineText.setFont(mineFont);
		mineText.setPosition(mineTextPosX, mineTextPosY);
		mineText.setFillColor(sf::Color::Yellow);
		mineText.setString(mineInitialText);
		mineText.setCharacterSize(textSize);
	}

	void GameplayUI::createTimerUI()
	{
		if (!timerFont.loadFromFile(mineTimerFontPath))
			std::cerr << "Error loading bubbleBobble font!" << std::endl;
		timerText.setFont(timerFont);
		timerText.setPosition(timerTextPosX, timerTextPosY);
		timerText.setFillColor(sf::Color::Yellow);
		timerText.setString(timerInitialText);
		timerText.setCharacterSize(textSize);
	}

	std::string GameplayUI::updateTimerUI(int _remain_time)
	{
		if (_remain_time < 10)
		{
			return ("00" + std::to_string(_remain_time));
		}
		else if (_remain_time < 100)
		{
			return ("0" + std::to_string(_remain_time));
		}
		else
		{
			return std::to_string(_remain_time);
		}
	}

	std::string GameplayUI::updateMineUI(int _remain_mine)
	{
		if (_remain_mine < 100)
		{
			return ("0" + std::to_string(_remain_mine));
		}
		else if (_remain_mine < 10)
		{
			return ("00" + std::to_string(_remain_mine));
		}
		else
			return ("" + std::to_string(_remain_mine));
	}

	void GameplayUI::initalizeResetButton()
	{
		restartButton = new UI::Button(restartButtonPath, sf::Vector2f(943.0f, 10), 64, 64);
	}

	void GameplayUI::registerRestartButtonCallBack(Gameplay::GameplayManager* gameplayManager)
	{
		restartButton->registerCallBackFunc([this, gameplayManager](UI::MouseButtonType _mouse_button_type)
			{
				restartButtonCallBack(_mouse_button_type, gameplayManager);
			});
	}

	void GameplayUI::restartButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager *gameplayManager)
	{
		if (_mouse_button_type == UI::MouseButtonType::LEFT_CLICK)
		{
			std::cout << "sa";
			gameplayManager->resetGame();
		}
	}
}