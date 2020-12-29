#ifndef BOARD_H 
#define BOARD_H

#include "GraphicHandlerInterface.h"

class Board
{
public:
    Board();
    ~Board();
    void Create();

	const int GetColumns() { return COLUMNS; }
	const int GetRows() { return ROWS; }
	bool** GetBoardMatrix() { return _mBoard; }

  void UpdateFigureInBoard(bool **shape
                         , int *shapePos
                         , const int shapeColumns
                         , const int shapeRows);

  void EraseFigureInBoard(bool **shape
                        , int *shapePos
                        , const int shapeColumns
                        , const int shapeRows);
private:
    const int COLUMNS = 10;
    const int ROWS = 20;

    bool **_mBoard;
};

#endif // !BOARD_H 
