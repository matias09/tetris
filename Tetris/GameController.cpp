#include "GameController.h"
#include "GameEvents.h"
#include "Config.h"

// Factories
#include "InputHandlerFactory.h"
#include "GraphicHandlerFactory.h"

// Game Flows
#include "GameFlowPlaying.h"

GameController::GameController()
{
    InputHandlerFactory inpFactory;
    _mInputHandler = inpFactory.GetInputHandler(CONFIG::INPUT_IMPLEMENTATION::SDL);

    GraphicHandlerFactory inpFactory;
    _mGraphicHandler = grpFactory.GetGraphicHandler(CONFIG::GRAPHIC_IMPLEMENTATION::SDL);

    _mActualState = GameController::GAME_STATES::IN_GAME;
}

GameController::~GameController()
{
    if (_mInputHandler != nullptr)
    {
        delete _mInputHandler;
        _mInputHandler = nullptr;
    }

    if (_mGraphicHandler != nullptr)
    {
        delete _mGraphicHandler;
        _mGraphicHandler = nullptr;
    }
}

int GameController::Run()
{
    //TODO chequiar que las instancias de los handlers no sean nulas
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

    if (_mActualState == GameController::GAME_STATES::EXIT_GAME)
    {
        _mActualState = GAME_EVENTS::EXIT_GAME_SUCCEFULLY;
    }
    return _mActualState;
}

