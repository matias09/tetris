#include <iostream>
#include <time.h>

#include "GameFlowPlaying.h"
#include "GameStates.h"

// Shapes
#include "LineShape.h"
#include "SquareShape.h"
#include "LShape.h"
#include "JShape.h"
#include "SShape.h"
#include "TShape.h"
#include "ZShape.h"

GameFlowPlaying::GameFlowPlaying()
{
    _mPosFrom = new int[COORDINATE_ELEMENTS];
    _mPosFrom[X_COORDINATE] = 4;
    _mPosFrom[Y_COORDINATE] = 0;

    _mPosTo = new int[COORDINATE_ELEMENTS];
    _mPosTo[X_COORDINATE] = 4;
    _mPosTo[Y_COORDINATE] = 0;

    _mDificultyGrade = 700;
    _mPuntuation = 0;

    _mThereIsLateralCollision = false;
    _mThereIsBottomCollision = false;
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
    // Build Board
    _mBoard = new Board();
    _mBoard->Create();

    // Get Random Shape
    _mShape = _GetRandomShape();

    bool exitGameFlowPlaying = false;
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    signed int input = 0;

    _mHigestRowMod = _mBoard->GetRows();

    do
    {
        currentTime = inpHandler.GetTicks();

        if (currentTime > (lastTime + CONSTANT_DIFICULTY + _mDificultyGrade))
        {
            input = InputHandlerInterface::KEY_ARROW_DOWN;
            lastTime = currentTime;
        }
        else
        {
            input = inpHandler.GetInput();
        }

        switch (input)
        {
        case InputHandlerInterface::KEY_SPACE:
            _ExecuteShapeRotate();
            break;
        case InputHandlerInterface::KEY_ARROW_DOWN:
            _ExecuteShapeDown();
            _mThereIsBottomCollision = _IsBottomOrDownShapeCollision();
            break;
        case InputHandlerInterface::KEY_ARROW_RIGHT:
            _ExecuteShapeRight();
            _mThereIsLateralCollision = _ThereIsCollision(true);
            break;
        case InputHandlerInterface::KEY_ARROW_LEFT:
            _ExecuteShapeLeft();
            _mThereIsLateralCollision = _ThereIsCollision(false);
            break;
        case InputHandlerInterface::KEY_SCAPE:
            exitGameFlowPlaying = GAME_STATES::EXIT_GAME;
            break;
        }

        if (_mThereIsBottomCollision == true)
        {
            if (_mPosFrom[Y_COORDINATE] < _mHigestRowMod)
            {
                _mHigestRowMod = _mPosFrom[Y_COORDINATE];
				if (_mHigestRowMod < 1)
				{
					exitGameFlowPlaying = GAME_STATES::EXIT_GAME;
				}
            }
            _mThereIsBottomCollision = false;
            _CheckRowsFilled();
            _ResetShapePtr();
            _mShape = _GetRandomShape();
        }
        else
        {
            if (_mThereIsLateralCollision == false)
            {
                _mBoard->EraseFigureInBoard(_mShape->GetMatrix(), _mPosFrom, _mShape->GetColumns(), _mShape->GetRows());
                _mBoard->UpdateFigureInBoard(_mShape->GetMatrix(), _mPosTo, _mShape->GetColumns(), _mShape->GetRows());
                _mPosFrom[X_COORDINATE] = _mPosTo[X_COORDINATE];
                _mPosFrom[Y_COORDINATE] = _mPosTo[Y_COORDINATE];
                grpHandler.Render(_mBoard->GetBoardMatrix(), _mBoard->GetColumns(), _mBoard->GetRows(), _mShape->GetRedVal(), _mShape->GetGreenVal(), _mShape->GetBlueVal());
            }
            else
            {
                _mThereIsLateralCollision = false;
            }
        }

        // If the Player fill rows, we increment Difficulty
		if (_mPuntuation > 0 && exitGameFlowPlaying == false)
		{
			if (_mDificultyGrade > 200)
			{
				SetDificultyGrade(_mDificultyGrade - (DIFFICULTY_UNIT * _mPuntuation));
			}

			SetScore(_mScore + SCORE_PER_LEVEL_UNIT);

			// If the Player fill rows, we increment Difficulty
			exitGameFlowPlaying = (_mPuntuation >= OBJECTIVE) ? true : false;
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
    unsigned short int randomShape = 0;
    Shape* shape;

    srand(time(NULL));
    randomShape = rand() % 7;

    switch (randomShape)
    {
    case 0:
        shape = new ZShape();
        break;
    case 1:
        shape = new SShape();
        break;
    case 2:
        shape = new SquareShape();
        break;
    case 3:
        shape = new LShape();
        break;
    case 4:
        shape = new JShape();
        break;
    case 5:
        shape = new LineShape();
        break;
    case 6:
        shape = new TShape();
        break;
    default:
        shape = new SquareShape();
    }
    shape->Create();
    return shape;
}

bool GameFlowPlaying::_ThereIsCollision(bool rightDirection)
{
    bool collision = false;
    signed int xActualPos;
    signed int cpyXActualPos;

    signed int yActualPos;
    signed int cpyYActualPos;

    int boardColumns = _mBoard->GetColumns();

	int shapeRows = _mShape->GetRows();
    int shapeColumns = _mShape->GetColumns();

	int iStartPoint;
	int iLimit;

	int jStartPoint;
	int jLimit;

	signed short int incrementAmount;
	signed int moveXPos = 0;

    if (rightDirection == true)
    {
		moveXPos = -1;
		iStartPoint = shapeRows - 1;
		iLimit = -1;
		jStartPoint = shapeColumns - 1;
		jLimit = -1;
		incrementAmount = -1;
		cpyXActualPos = _mPosTo[X_COORDINATE] + (shapeColumns - 1);
		cpyYActualPos = _mPosTo[Y_COORDINATE] + (shapeRows - 1);
    }
	else
	{
		moveXPos = 1;
		iStartPoint = 0;
		iLimit = shapeRows;
		jStartPoint = 0;
		jLimit = shapeColumns;
		incrementAmount = 1;
		cpyXActualPos = _mPosTo[X_COORDINATE];
		cpyYActualPos = _mPosTo[Y_COORDINATE];
	}

	xActualPos = cpyXActualPos;
	yActualPos = cpyYActualPos;

    if (xActualPos != -1 && xActualPos != boardColumns)
    {
        bool** shapeMatrix = _mShape->GetMatrix();
        bool** boardMatrix = _mBoard->GetBoardMatrix();

        for (int i = iStartPoint; i != iLimit && collision == false; i += incrementAmount)
        {
            for (int j = jStartPoint; j != jLimit; j += incrementAmount)
            {
                if (shapeMatrix[i][j] == 1)
                {
                    if (boardMatrix[yActualPos][xActualPos] == 1)
                    {
                        _mPosTo[X_COORDINATE] = _mPosFrom[X_COORDINATE];
                        _mPosTo[Y_COORDINATE] = _mPosFrom[Y_COORDINATE];
                        collision = true;
                        break;
                    }
                }
				else
				{
					xActualPos = xActualPos + moveXPos;
				}
            }

            // This is increasing Y Axis
            yActualPos = yActualPos + incrementAmount;

            // Reset X Axis
            xActualPos = cpyXActualPos;
        }
    }
    else
    {
        _mPosTo[X_COORDINATE] = _mPosFrom[X_COORDINATE];
        _mPosTo[Y_COORDINATE] = _mPosFrom[Y_COORDINATE];
        collision = true;
    }

    return collision;
}

bool GameFlowPlaying::_IsBottomOrDownShapeCollision()
{
    bool collision = false;
    int boardRows = _mBoard->GetRows();
    int boardColumns = _mBoard->GetColumns();

    int shapeColumns = _mShape->GetColumns();
    int shapeRows = _mShape->GetRows();

    signed int xActualPos = _mPosTo[X_COORDINATE];
    signed int yActualPos;
    signed int cpyYActualPos = _mPosTo[Y_COORDINATE] + (shapeRows - 1);

	signed short int iLimit = shapeRows - 1;

	yActualPos = cpyYActualPos;

    if (yActualPos != boardRows)
    {
        bool** shapeMatrix = _mShape->GetMatrix();
        bool** boardMatrix = _mBoard->GetBoardMatrix();

		for (int j = 0; j < shapeColumns && collision == false; j++)
        {
			for (int i = iLimit; i > -1; i--)
            {
                if (shapeMatrix[i][j] == 1)
                {
                    if (boardMatrix[yActualPos][xActualPos] == 1)
                    {
                        collision = true;
                        break;
                    }
                }
				else
				{
					// Increment Y Axis or change to the next column Shape
					yActualPos--;
				}
            }

			// Reset Y Axis
			yActualPos = cpyYActualPos;

            // Increment X Axis or change to the next column Shape
            xActualPos++;
        }
    }
    else
    {
        collision = true;
    }
    return collision;
}

void GameFlowPlaying::_ResetShapePtr()
{
    delete _mShape;

    _mPosFrom[X_COORDINATE] = 4;
    _mPosFrom[Y_COORDINATE] = 0;

    _mPosTo[X_COORDINATE] = 4;
    _mPosTo[Y_COORDINATE] = 0;
}

void GameFlowPlaying::_ExecuteShapeRotate()
{
    // Clear actual Shape from the board
    _mBoard->EraseFigureInBoard(_mShape->GetMatrix(), _mPosFrom, _mShape->GetColumns(), _mShape->GetRows());

    // Change shapeMatrix Form
    _RotateShape();

    // Save Shape actual rotation just in case we have to Roll Back
    actShpRot = _mShape->GetActualRotation();

    if (_IsBottomOrDownShapeCollision())
    {
        SetThereIsBottomCollision(true);
    }
    else if (_ThereIsCollision(true) || _ThereIsCollision(false))
    {
        SetThereIsLateralCollision(true);
    }

    if (_mThereIsBottomCollision == true || _mThereIsLateralCollision == true)
    {
        _mShape->SetActualRotation(actShpRot);

        // Roll Back shapeMatrix Form
        _RotateShape();

        _mBoard->UpdateFigureInBoard(_mShape->GetMatrix(), _mPosTo, _mShape->GetColumns(), _mShape->GetRows());

        SetThereIsBottomCollision(false);
        SetThereIsLateralCollision(false);
    }

	// Calculate _mPostTo using the Rotation Coordinate of the Shape
//	_CalculateNewXYPosition();
	// Check if there is no Collision
}

void GameFlowPlaying::_CalculateNewXYPosition()
{}

void GameFlowPlaying::_RotateShape()
{
	unsigned short int actualRotation = _mShape->GetActualRotation();
    switch (actualRotation)
    {
    case 1:
        _mShape->_RotateToUp();
    break;
    case 2:
        _mShape->_RotateToLeft();
    break;
    case 3:
        _mShape->_RotateToDown();
    break;
    case 4:
		actualRotation = 0;
        _mShape->_RotateToRight();
    break;
    }

	actualRotation++;
	_mShape->SetActualRotation(actualRotation);
}

void GameFlowPlaying::_ExecuteShapeDown()
{
    ++_mPosTo[Y_COORDINATE];
}

void GameFlowPlaying::_ExecuteShapeRight()
{
    ++_mPosTo[X_COORDINATE];
}

void GameFlowPlaying::_ExecuteShapeLeft()
{
    --_mPosTo[X_COORDINATE];
}

void GameFlowPlaying::_CheckRowsFilled()
{
    unsigned short int rowBlocksFilled = 0;
    int boardColumns = _mBoard->GetColumns();
    int boardRows = _mBoard->GetRows();
    bool** boardMatrix = _mBoard->GetBoardMatrix();
    bool rowDeleted = false;
    int i = boardRows - 1;
    int firstEmptyRow = _mHigestRowMod - 1;

    for (; i > firstEmptyRow; i--)
    {
        for (int j = 0; j < boardColumns; j++)
        {
            if (boardMatrix[i][j] != 0)
            {
                rowBlocksFilled++;
            }
        }

        if (rowBlocksFilled == boardColumns)
        {
            for (int j = 0; j < boardColumns; j++)
            {
                boardMatrix[i][j] = 0;
            }

			_DownGradeRestOfRows(i);

            SetPuntuation(_mPuntuation + PUNTUATION_UNIT);

            rowDeleted = true;
			i++;
        }
        rowBlocksFilled = 0;
    }
}

void GameFlowPlaying::_DownGradeRestOfRows(unsigned int initialRowToDraw)
{
    int boardColumns = _mBoard->GetColumns();
    int boardRows = _mBoard->GetRows();
    bool** boardMatrix = _mBoard->GetBoardMatrix();
    int i = initialRowToDraw;
    int k = initialRowToDraw - 1;
    int rowsToUpdateCount = k - (_mHigestRowMod - 1);
    int iterationCount = 0;

    for (; iterationCount < rowsToUpdateCount; iterationCount++, i--, k--)
    {
        for (int j = 0; j < boardColumns; j++)
        {
            boardMatrix[i][j] = boardMatrix[k][j];
            boardMatrix[k][j] = 0;
        }
    }
}
