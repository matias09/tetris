#include "GameFlowPlaying.h"
#include "GameStates.h"

signed int GameFlowPlaying::Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler)
{
    // creo el tablero
    // obtengo la figura

    signed int input = 0;
    do
    {
        input = inpHandler.GetInput();
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
            input = GAME_STATES::EXIT_GAME;
            break;
        }
    } while (input != GAME_STATES::EXIT_GAME);

    return input;
}

void GameFlowPlaying::Pause()
{}

void GameFlowPlaying::Exit()
{}
