#include "IShape.h"

IShape::IShape()
{
    _mMatrix = new bool*[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        _mMatrix[i] = new bool[COLUMNS];
    }

    _mPosition = new int[COORDINATE_ELEMENTS];
    _mPosition[X_COORDINATE] = 2;
    _mPosition[Y_COORDINATE] = 0;
}

bool** IShape::Create()
{
    signed int xActualPos = 0;
    signed int yActualPos = _mPosition[Y_COORDINATE];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (j == MIDDLE_COLUMN_NUM)
            {
                xActualPos = _mPosition[X_COORDINATE];
                _mMatrix[yActualPos][xActualPos] = 1;
            }
        }
        yActualPos = i + _mPosition[Y_COORDINATE];
        xActualPos = 0;
    }

    return _mMatrix;
}

void IShape::Rotate()
{}

void IShape::MoveDown()
{
}

void IShape::MoveUp()
{
}

void IShape::MoveRight()
{
}

void IShape::MoveLeft()
{
}
