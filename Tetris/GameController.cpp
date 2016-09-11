#include "GameController.h"
#include "Config.h"
#include "GameEvents.h"
#include "GameStates.h"

// Factories
#include "InputHandlerFactory.h"
#include "GraphicHandlerFactory.h"

// Game Flows
#include "GameFlowPlaying.h"

GameController::GameController()
{
    InputHandlerFactory inpFactory;
    _mInputHandler = inpFactory.GetInputHandler(CONFIG::INPUT_IMPLEMENTATION::SDL);

    GraphicHandlerFactory grpFactory;
    _mGraphicHandler = grpFactory.GetGraphicHandler(CONFIG::GRAPHIC_IMPLEMENTATION::SDL);

    _mActualState = GAME_STATES::IN_GAME;
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
    GAME_STATES gameStates;

    while (_mActualState != GAME_EVENTS::EXIT_GAME_SUCCEFULLY)
    {
        switch (_mActualState)
        {
        case GAME_STATES::IN_GAME:
            _mActualState = _mGameFlow->Run(*_mInputHandler, *_mGraphicHandler, gameStates);
        break;
        case GAME_STATES::EXIT_GAME:
            _mActualState = GAME_EVENTS::EXIT_GAME_SUCCEFULLY;
        }
    }

    return _mActualState;
}

