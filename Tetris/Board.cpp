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

void Board::UpdateFigureInBoard(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
    unsigned int xActualPos = shapePos[0];
    unsigned int yActualPos = shapePos[1];

	// Loop to set Position To
	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if (shape[i][j] != 0)
			{
			   _mBoard[yActualPos + i][xActualPos + j] = shape[i][j];
			}
		}

		// Reset X to begin from the start of row
        xActualPos = shapePos[0];
    }
}

void Board::EraseFigureInBoard(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
    unsigned int xActualPos = shapePos[0];
    unsigned int yActualPos = shapePos[1];

	// Loop to erase Position From 
	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if (shape[i][j] != 0)
			{
			   _mBoard[yActualPos + i][xActualPos + j] = 0;
			}
		}

		// Reset X to begin from the start of row
        xActualPos = shapePos[0];
    }
}