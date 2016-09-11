#ifndef BOARD_H 
#define BOARD_H

#include "GraphicHandlerInterface.h"

class Board
{
public:
    Board(const GraphicHandlerInterface& grpHandler);
    ~Board();
    void Create();
    void Update(const bool** figure);
private:
    bool _ThereIsCollision(const bool** figure);

    const int COLUMNS = 10;
    const int ROWS = 20;
    const int PIXEL_BOARD_WIDTH = 15;
    const int PIXEL_SPACE_BETWEEN = 5;

    bool** _mBoard;
    GraphicHandlerInterface _mGrpHandler;
};

#endif // !BOARD_H 