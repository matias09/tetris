#include "Board.h"

Board::Board()
{
    _mBoard = new bool*[ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
        _mBoard[i] = new bool[COLUMNS];
    }
}

Board::~Board()
{
   if (_mBoard != nullptr)
   {
       for (int i = 0; i < ROWS; ++i)
       {
           delete[] _mBoard[i];
           _mBoard[i] = nullptr;
       } 

       delete[] _mBoard;
       _mBoard = nullptr;
   }
}

void Board::Create()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            _mBoard[i][j] = 0;
        }
    }
}

void Board::UpdateFigureInBoard(bool** shape, int* shapePosFrom, int* shapePosTo, const int shapeColumns, const int shapeRows)
{
    unsigned int xActualPosFrom = shapePosFrom[0];
    unsigned int yActualPosFrom = shapePosFrom[1];

    unsigned int xActualPosTo = shapePosTo[0];
    unsigned int yActualPosTo = shapePosTo[1];

	// Loop to erase Pos From 
	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if (shape[i][j] != 0)
			{
			   _mBoard[yActualPosFrom + i][xActualPosFrom + j] = 0;
			}
		}

		// Reseteo X para que comience desde el principio de la row
        xActualPosFrom = shapePosFrom[0];
    }

	// Loop to set Pos To
	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if (shape[i][j] != 0)
			{
			   _mBoard[yActualPosTo + i][xActualPosTo + j] = shape[i][j];
			}
		}

		// Reseteo X para que comience desde el principio de la row
        xActualPosTo = shapePosTo[0];
    }
}