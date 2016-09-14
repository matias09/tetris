#include "Board.h"

Board::Board(GraphicHandlerInterface& grpHandler) : _mGrpHandler(grpHandler)
{
    _mBoard = new bool*[ROWS];
    for (int i = 0; i < ROWS; ++i)
    {
        _mBoard[i] = new bool[COLUMNS];
    }
}

Board::~Board()
{}

void Board::Create()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            _mBoard[i][j] = 0;
        }
    }

    _mGrpHandler.Render(_mBoard, COLUMNS, ROWS);
}

void Board::Update(bool** figure, int* figurePos, const int colums, const int rows)
{
    // Check if there any collision
    _ThereIsCollision(figure, figurePos, colums, rows);
    _UpdateFigureInBoard(figure, figurePos, colums, rows);
    
    _mGrpHandler.Render(_mBoard, COLUMNS, ROWS);
}

void Board::_UpdateFigureInBoard(bool** figure, int* figurePos, const int colums, const int rows)
{
    signed int xActualPos = 0;
    signed int yActualPos = figurePos[1];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < colums; ++j)
        {
            xActualPos = j + figurePos[0];
            _mBoard[yActualPos][xActualPos] = figure[i][j];
        }
        yActualPos = i + figurePos[1];
        xActualPos = 0;
    }
}

bool Board::_ThereIsCollision(bool** figure, int* figurePos, const int colums, const int rows)
{
    return false;
}
