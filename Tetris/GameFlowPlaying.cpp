#include "GameFlowPlaying.h"

GameFlowPlaying::GameFlowPlaying()
{
}

GameFlowPlaying::~GameFlowPlaying()
{}

signed int GameFlowPlaying::Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler, GAME_STATES gameStates)
{
    // creo el tablero
    // obtengo la figura

    signed int input = inpHandler.GetInput();
        switch (input)
        {
        case InputHandlerInterface::KEY_ARROW_UP:
            break;
        case InputHandlerInterface::KEY_ARROW_DOWN:
            break;
        case InputHandlerInterface::KEY_ARROW_RIGHT:
            break;
        case InputHandlerInterface::KEY_ARROW_LEFT:
            break;
        case InputHandlerInterface::KEY_SCAPE:
            return GAME_STATES::MAIN_MENU;
            break;
        }

    return input;
}

void GameFlowPlaying::Pause()
{}

void GameFlowPlaying::Exit()
{}
