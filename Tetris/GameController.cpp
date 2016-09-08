#include "GameController.h"
#include "GameFlowPlaying.h"

GameController::GameController()
{
    _mActualState = GameController::GAME_STATES::IN_GAME;
}

GameController::~GameController()
{}

int GameController::Run()
{
    _mGameFlow = new GameFlowPlaying();
    while (_mActualState != -1)
    {
        switch (_mActualState)
        {
        case GameController::GAME_STATES::IN_GAME:
            _mActualState = _mGameFlow->Run();
        break;
        case GameController::GAME_STATES::EXIT_GAME:
            _mActualState = GameController::GAME_STATES::EXIT_GAME;
        }
    }

    return 1;
}

