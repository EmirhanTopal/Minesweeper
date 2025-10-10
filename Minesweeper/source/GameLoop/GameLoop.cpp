#include "../../header/GameLoop/GameLoop.h"
#include "../../header/Time/TimeManager.h"
#include <iostream>
#include "..\..\header\Sound\SoundManager.h"
#include "..\..\header\Gameplay\gameplayManager.h"

GameState GameLoop::current_state = GameState::GAMEPLAY;

GameLoop::GameLoop() { initialize(); }

void GameLoop::initialize()
{
    // Create Managers:
    window_manager = new GameWindowManager();
    game_window = window_manager->getGameWindow();
    event_manager = new EventPollingManager(game_window);

    //splash_screen_manager = new SplashScreenManager(game_window);

    // Initialize Sounds:
    Sound::SoundManager::Initialize();
    //Sound::SoundManager::PlayBackgroundMusic();

    // Initialize Time:
    Time::TimeManager::initialize();

    //initialize gameplaymanager:
    gameplay_manager = new Gameplay::GameplayManager();
    gameplay_manager->initialize();
}

GameLoop::~GameLoop()
{
    delete window_manager;
    delete event_manager;
    delete splash_screen_manager;
}

void GameLoop::update()
{
    Time::TimeManager::update();
    event_manager->update();
    window_manager->update();

    switch (current_state)
    {
    case GameState::MAIN_MENU:
        break;
    case GameState::GAMEPLAY:
        gameplay_manager->update(*event_manager, *window_manager->getGameWindow());
        break;
    case GameState::EXIT:
        game_window->close();
        break;
    }

}

void GameLoop::render()
{
    game_window->clear();
    window_manager->render();

    switch (current_state)
    {
    case GameState::MAIN_MENU:
        break;
    case GameState::GAMEPLAY:
        gameplay_manager->render(*window_manager->getGameWindow());
        break;
    }

    game_window->display();
}

void GameLoop::run()
{
    while (window_manager->isGameWindowOpen())
    {
        event_manager->processEvents();
        update();
        render();
    }
}

void GameLoop::setGameState(GameState state_to_set) { GameLoop::current_state = state_to_set; }