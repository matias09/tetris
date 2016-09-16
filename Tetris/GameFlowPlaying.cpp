#include <iostream>

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
	_mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());

	const bool HAS_TO_RESET = true;
	bool exitGameFlowPlaying = false;
    signed int input = 0;
    do
    {
		input = 0;
        input = inpHandler.GetInput();
        switch (input)
        {
        case InputHandlerInterface::KEY_ARROW_UP:
			printf("GAME_FLOW :: up \n ");
			_mBoard->EraseLastPosition(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
			_mShape->MoveUp();
			_mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
            break;
        case InputHandlerInterface::KEY_ARROW_DOWN:
			printf("GAME_FLOW :: down \n ");
			_mBoard->EraseLastPosition(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
			_mShape->MoveDown();
			_mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
            break;
        case InputHandlerInterface::KEY_ARROW_RIGHT:
			printf("GAME_FLOW :: right \n ");
			_mBoard->EraseLastPosition(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
			_mShape->MoveRight();
			_mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
            break;
        case InputHandlerInterface::KEY_ARROW_LEFT:
			printf("GAME_FLOW :: left \n ");
			_mBoard->EraseLastPosition(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
			_mShape->MoveLeft();
			_mBoard->Update(_mShape->GetMatrix(), _mShape->GetPosition(), _mShape->GetColumns(), _mShape->GetRows());
            break;
        case InputHandlerInterface::KEY_SCAPE:
			printf("GAME_FLOW :: scape \n ");
            exitGameFlowPlaying = GAME_STATES::EXIT_GAME;
            break;
        }
    } while (exitGameFlowPlaying != GAME_STATES::EXIT_GAME);

    return exitGameFlowPlaying;
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
