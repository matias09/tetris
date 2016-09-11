#include "Board.h"

Board::Board(const GraphicHandlerInterface& grpHandler)
{
    _mGrpHandler = grpHandler;
    _mBoard[COLUMNS][ROWS] = 0;
}

Board::~Board()
{}

void Board::Create()
{
    for (int i = 0; i < COLUMNS; ++i)
    {
        for (int j = 0; j < ROWS; ++j)
        {
            _mBoard[i][j] = 0;
        }
    }
}

void Board::Update(const bool** figure)
{
    // Check if there any collision
    _ThereIsCollision(figure);
    _mGrpHandler.Render(_mBoard);
}

bool Board::_ThereIsCollision(const bool** figure)
{
    return false;
}
