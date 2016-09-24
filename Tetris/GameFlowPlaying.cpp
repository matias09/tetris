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

    _mDificultyGrade = 0;
    _mPuntuation = 0;
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
    bool thereIsCollision = false;
    bool needOfOtherShape = false;
    unsigned int currentTime = 0;
    unsigned int lastTime = 0;
    signed int input = 0;

    _mHigestRowMod = _mBoard->GetRows();

    do
    {
        // If the Player reach the objective, we increment Difficulty
        if (_mPuntuation == OBJECTIVE)
        {
#ifdef DEBUG
            printf("GAME_FLOW :: Level Ended \n ");
#endif
            SetDificultyGrade(_mDificultyGrade + DIFFICULTY_UNIT);
            SetPuntuation(0);
        }

        currentTime = inpHandler.GetTicks();

        // Fix : Check _mDifficulty because, when some level is reached, the timer not work
        //if (currentTime > (lastTime + (1000 - _mDificultyGrade)))
        if (currentTime > (lastTime + 1000))
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
            //_ExecuteShapeRotate();
            break;
        case InputHandlerInterface::KEY_ARROW_DOWN:
            _ExecuteShapeDown();
            needOfOtherShape = _IsBottomOrDownShapeCollision();
            break;
        case InputHandlerInterface::KEY_ARROW_RIGHT:
            _ExecuteShapeRight();
            thereIsCollision = _ThereIsCollision(true);
            break;
        case InputHandlerInterface::KEY_ARROW_LEFT:
            _ExecuteShapeLeft();
            thereIsCollision = _ThereIsCollision(false);
            break;
        case InputHandlerInterface::KEY_SCAPE:
#ifdef DEBUG
            printf("GAME_FLOW :: scape \n ");
#endif
            exitGameFlowPlaying = GAME_STATES::EXIT_GAME;
            break;
        }

        if (needOfOtherShape == true)
        {
            if (_mPosFrom[Y_COORDINATE] < _mHigestRowMod)
            {
                _mHigestRowMod = _mPosFrom[Y_COORDINATE];
            }
            needOfOtherShape = false;
            _CheckRowsFilled();
            _mShape = _GetRandomShape();
        }
        else
        {
            if (thereIsCollision == false)
            {
                _mBoard->UpdateFigureInBoard(_mShape->GetMatrix(), _mPosFrom, _mPosTo, _mShape->GetColumns(), _mShape->GetRows());
                _mPosFrom[X_COORDINATE] = _mPosTo[X_COORDINATE];
                _mPosFrom[Y_COORDINATE] = _mPosTo[Y_COORDINATE];
                grpHandler.Render(_mBoard->GetBoardMatrix(), _mBoard->GetColumns(), _mBoard->GetRows(), _mShape->GetRedVal(), _mShape->GetGreenVal(), _mShape->GetBlueVal());
            }
            else
            {
                thereIsCollision = false;
            }
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
    _ResetShapePtr();

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
#ifdef DEBUG
    printf("GAME_FLOW :: SHAPE ROTATE \n ");
#endif DEBUG
	_mShape->Rotate();
}

void GameFlowPlaying::_ExecuteShapeDown()
{
#ifdef DEBUG
    printf("GAME_FLOW :: SHAPE DOWN \n ");
#endif DEBUG
    ++_mPosTo[Y_COORDINATE];
}

void GameFlowPlaying::_ExecuteShapeRight()
{
#ifdef DEBUG
    printf("GAME_FLOW :: SHAPE RIGHT \n ");
#endif DEBUG
    ++_mPosTo[X_COORDINATE];
}

void GameFlowPlaying::_ExecuteShapeLeft()
{
#ifdef DEBUG
    printf("GAME_FLOW :: SHAPE LEFT \n ");
#endif DEBUG
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
    int firstUnfufilledRow = _mHigestRowMod - 1;

    for (; i >= firstUnfufilledRow; i--)
    {
        for (int j = 0; j < boardColumns; j++)
        {
            if (boardMatrix[i][j] == 0)
            {
                if (rowDeleted == true)
                {
                    _DownGradeRestOfRows(i);
                }
            }
            else
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

            SetPuntuation(_mPuntuation + PUNTUATION_UNIT);
            rowDeleted = true;
        }
        rowBlocksFilled = 0;
    }
}

void GameFlowPlaying::_DownGradeRestOfRows(unsigned int beginningRow)
{
    unsigned short int rowBlocksEmpty = 0;
    int boardColumns = _mBoard->GetColumns();
    int boardRows = _mBoard->GetRows();
    bool** boardMatrix = _mBoard->GetBoardMatrix();
    int i = boardRows - 1;
    int k = beginningRow;
    int rowsToUpdateCount = beginningRow - _mHigestRowMod;
    int iterationCount = 0;

    for (; iterationCount <= rowsToUpdateCount; iterationCount++, i--, k--)
    {
        for (int j = 0; j < boardColumns; j++)
        {
            boardMatrix[i][j] = boardMatrix[k][j];
            boardMatrix[k][j] = 0;
        }
    }
}
