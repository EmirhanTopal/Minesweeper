#include "../../header/UI/GameplayUI/MainMenu.h"
#include <iostream>

namespace UI
{
	MainMenuManager::MainMenuManager(Gameplay::GameplayManager* gameplayManager)
	{
		initialize(gameplayManager);
	}

	void MainMenuManager::initialize(Gameplay::GameplayManager* gameplayManager)
	{
		initalizeVariables(gameplayManager);
	}

	void MainMenuManager::initalizeVariables(Gameplay::GameplayManager* gameplayManager)
	{
		createButtons();
		registerPlayButtonCallBack(gameplayManager);
		registerQuitButtonCallBack(gameplayManager);
	}

	void MainMenuManager::update(sf::RenderWindow& _game_window, Event::EventPollingManager _event_manager)
	{
		playButton->detectMouseClick(_event_manager, _game_window);
		quitButton->detectMouseClick(_event_manager, _game_window);
	}

	void MainMenuManager::render(sf::RenderWindow &_game_window)
	{
		playButton->render(_game_window);
		quitButton->render(_game_window);
	}

	void MainMenuManager::createButtons()
	{
		playButton = new Button(playTexturePath, sf::Vector2f(playPosX, playPosY), 128, 128);
		quitButton = new Button(quitTexturePath, sf::Vector2f(quitPosX, quitPosY), 128, 128);
	}

	void MainMenuManager::registerPlayButtonCallBack(Gameplay::GameplayManager* gameplayManager)
	{
		playButton->registerCallBackFunc([this, gameplayManager](MouseButtonType _mouse_button_type) 
		{
				playButtonCallBack(_mouse_button_type, gameplayManager);
		});
	}

	void MainMenuManager::playButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager* gameplayManager)
	{
		if (_mouse_button_type == MouseButtonType::LEFT_CLICK)
		{
			gameplayManager->play();
		}
	}

	void MainMenuManager::registerQuitButtonCallBack(Gameplay::GameplayManager* gameplayManager)
	{
		quitButton->registerCallBackFunc([this, gameplayManager](MouseButtonType _mouse_button_type)
		{
			quitButtonCallBack(_mouse_button_type, gameplayManager);
		});
	}

	void MainMenuManager::quitButtonCallBack(UI::MouseButtonType _mouse_button_type, Gameplay::GameplayManager* gameplayManager)
	{
		if (_mouse_button_type == MouseButtonType::LEFT_CLICK)
		{
			gameplayManager->quit();
		}
	}
}