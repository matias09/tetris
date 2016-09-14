#include "GameFlowPlaying.h"
#include "GameStates.h"
#include "IShape.h"

signed int GameFlowPlaying::Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler)
{
    // creo el tablero
    _mBoard = new Board(grpHandler);
    _mBoard->Create();

    // obtengo la figura
    _mShape = _GetRandomShape();

    signed int input = 0;
    do
    {
        _mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
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

Shape* GameFlowPlaying::_GetRandomShape()
{
    Shape* shape = new IShape();
    shape->Create();
    return shape;
}
