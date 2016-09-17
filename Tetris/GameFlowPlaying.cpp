#include <iostream>

#include "GameFlowPlaying.h"
#include "GameStates.h"
#include "IShape.h"

GameFlowPlaying::GameFlowPlaying()
{
    _mPosFrom = new int[COORDINATE_ELEMENTS];
    _mPosFrom[X_COORDINATE] = 4;
    _mPosFrom[Y_COORDINATE] = 0;

    _mPosTo = new int[COORDINATE_ELEMENTS];
    _mPosTo[X_COORDINATE] = 4;
    _mPosTo[Y_COORDINATE] = 0;
}
GameFlowPlaying::~GameFlowPlaying()
{
    if (_mBoard != nullptr)
    {
        delete _mBoard;
        _mBoard = nullptr;
    }

    if (_mShape != nullptr)
    {
        delete _mShape;
        _mShape = nullptr;
    }
}

signed int GameFlowPlaying::Run(InputHandlerInterface& inpHandler, GraphicHandlerInterface& grpHandler)
{
    // creo el tablero
    _mBoard = new Board();
    _mBoard->Create();

    // obtengo la figura
    _mShape = _GetRandomShape();
	//_mBoard->UpdateFigureInBoard(_mShape->GetMatrix(), _mPosFrom, _mPosTo, _mShape->GetColumns(), _mShape->GetRows());

	bool exitGameFlowPlaying = false;
    signed int input;

    do
    {
        input = inpHandler.GetInput();
		switch (input)
		{
		case InputHandlerInterface::KEY_SPACE:
			_ExecuteShapeRotate();
            break;
        case InputHandlerInterface::KEY_ARROW_DOWN:
			_ExecuteShapeDown();
            break;
        case InputHandlerInterface::KEY_ARROW_RIGHT:
			_ExecuteShapeRight();
            break;
        case InputHandlerInterface::KEY_ARROW_LEFT:
			_ExecuteShapeLeft();
            break;
        case InputHandlerInterface::KEY_SCAPE:
#ifdef DEBUG
			printf("GAME_FLOW :: scape \n ");
#endif
            exitGameFlowPlaying = GAME_STATES::EXIT_GAME;
            break;
        }

		if (_ThereIsCollision() == false)
		{
			_mBoard->UpdateFigureInBoard(_mShape->GetMatrix(), _mPosFrom, _mPosTo, _mShape->GetColumns(), _mShape->GetRows());
			_mPosFrom[X_COORDINATE] = _mPosTo[X_COORDINATE];
			_mPosFrom[Y_COORDINATE] = _mPosTo[Y_COORDINATE];
			grpHandler.Render(_mBoard->GetBoardMatrix(), _mBoard->GetColumns(), _mBoard->GetRows(), _mShape->GetColorMod());
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

bool GameFlowPlaying::_ThereIsCollision()
{
	bool collision = false;
	signed int xActualPos = _mPosTo[X_COORDINATE];
	signed int yActualPos = _mPosTo[Y_COORDINATE];
	int boardColumns = _mBoard->GetColumns();
	int boardRows = _mBoard->GetRows();
	int shapeColumns = _mShape->GetColumns();
	int shapeRows = _mShape->GetRows();
	bool** boardMatrix = _mBoard->GetBoardMatrix();

	for (int i = 0; i < shapeRows && collision == false; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if ((xActualPos == -1 || xActualPos == boardColumns)
				|| yActualPos == boardRows
				|| boardMatrix[yActualPos][xActualPos] != 0
			) {
				_mPosTo[X_COORDINATE] = _mPosFrom[X_COORDINATE];
				_mPosTo[Y_COORDINATE] = _mPosFrom[Y_COORDINATE];
				collision = true;
				break;
			}
			xActualPos++;
		}

		// Esto va corriendo la posicion en Y
		yActualPos++;

		// Reseteo X para que comience desde el principio de la row
        xActualPos = _mPosTo[X_COORDINATE];
    }
    return collision;
}

void GameFlowPlaying::_ExecuteShapeRotate()
{
#ifdef DEBUG
	printf("GAME_FLOW :: up \n ");
#endif DEBUG
	_mShape->Rotate();
}

void GameFlowPlaying::_ExecuteShapeDown()
{
#ifdef DEBUG
	printf("GAME_FLOW :: SPACE_BAR \n ");
#endif DEBUG
	_mShape->MoveDown(_mPosTo, Y_COORDINATE);
}

void GameFlowPlaying::_ExecuteShapeRight()
{
#ifdef DEBUG
	printf("GAME_FLOW :: up \n ");
#endif DEBUG
	_mShape->MoveRight(_mPosTo, X_COORDINATE);
}

void GameFlowPlaying::_ExecuteShapeLeft()
{
#ifdef DEBUG
	printf("GAME_FLOW :: up \n ");
#endif DEBUG
	_mShape->MoveLeft(_mPosTo, X_COORDINATE);
}