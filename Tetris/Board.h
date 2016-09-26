#ifndef BOARD_H 
#define BOARD_H

#include "GraphicHandlerInterface.h"

class Board
{
public:
    Board();
    ~Board();
    void Create();
    void UpdateFigureInBoard(bool** shape, int* shapePos, const int colums, const int rows);
	void EraseFigureInBoard(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows);

	// Get
	const int GetColumns() { return COLUMNS; }
	const int GetRows() { return ROWS; }
	bool** GetBoardMatrix() { return _mBoard; }

	bool& MakeCopy(bool** boardMatrix)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				boardMatrix[i][j] = _mBoard[i][j];
			}
		}

		return **boardMatrix;
	};

    void MakeRollBack(bool** boardMatrix)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				_mBoard[i][j] = boardMatrix[i][j];
			}
		}
	};

private:
    const int COLUMNS = 10;
    const int ROWS = 20;

    bool** _mBoard;
};

#endif // !BOARD_H 