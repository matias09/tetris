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
    _mInputHandler = inpFactory.GetInputHandler(INPUT_CONFIG::INPUT_IMPLEMENTATION::SDL);

    GraphicHandlerFactory grpFactory;
    _mGraphicHandler = grpFactory.GetGraphicHandler(GRAPHIC_CONFIG::GRAPHIC_IMPLEMENTATION::SDL);

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

bool GameController::ThereIsAnyToolError()
{
    bool toolError = false;

    if (_mInputHandler == nullptr)
    {
        toolError = true;
    }
    else if (_mInputHandler->IsInputSdlEnabled() != false)
    {
        toolError = true;
    }

    if (_mGraphicHandler == nullptr)
    {
        toolError = true;
    }
    else if (_mGraphicHandler->IsGraphicSdlEnabled() != false)
    {
        toolError = true;
    }

    return toolError;
}

int GameController::Run()
{
    //TODO chequiar que las instancias de los handlers no sean nulas
    _mGameFlow = new GameFlowPlaying();

    while (_mActualState != GAME_EVENTS::EXIT_GAME_SUCCEFULLY)
    {
        switch (_mActualState)
        {
        case GAME_STATES::IN_GAME:
            _mActualState = _mGameFlow->Run(*_mInputHandler, *_mGraphicHandler);
            break;
        case GAME_STATES::EXIT_GAME:
            _mActualState = GAME_EVENTS::EXIT_GAME_SUCCEFULLY;
            break;
        }
    }

    return _mActualState;
}

