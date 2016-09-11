#include "IShape.h"

const int COLUMNS = 5;
const int ROWS = 4;

bool IShape::Create()
{
    bool shape[COLUMNS][ROWS];

    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (i == 2)
            {
                shape[i][j] = 1;
            }
        }
    }

    return shape;
}

void IShape::Rotate(Shape& shape)
{}
