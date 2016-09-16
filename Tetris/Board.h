#ifndef BOARD_H 
#define BOARD_H

#include "GraphicHandlerInterface.h"

class Board
{
public:
    Board(GraphicHandlerInterface& grpHandler);
    ~Board();
    void Create();
    void Update(bool** figure, int* figurePos, const int colums, const int rows);
    void EraseLastPosition(bool** figure, int* figurePos, const int colums, const int rows);
private:
    bool _ThereIsCollision(bool** figure, int* figurePos, const int colums, const int rows);
    void _UpdateFigureInBoard(bool** figure, int* figurePos, const int colums, const int rows);

    const int COLUMNS = 10;
    const int ROWS = 20;

    bool** _mBoard;
    GraphicHandlerInterface& _mGrpHandler;
};

#endif // !BOARD_H 