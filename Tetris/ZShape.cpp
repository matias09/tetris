#include "ZShape.h"

ZShape::ZShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }
}

ZShape::~ZShape()
{
   if (_mMatrix != nullptr)
   {
       for (int i = 0; i < SHAPE_DIMENSION; ++i)
       {
           delete[] _mMatrix[i];
           _mMatrix[i] = nullptr;
       } 

	   delete[] _mMatrix;
       _mMatrix = nullptr;
   }
}

bool** ZShape::Create()
{
	unsigned short int columns = 3;
	unsigned short int rows = 2;

	for (unsigned short int i = 0; i < rows; i++)
	{
		for (unsigned short int j = 0; j < columns; j++)
		{
			if ((j < 2 && i == 0) || (j > 0 && i == 1))
			{
				_mMatrix[i][j] = 1;
			}
			else
			{
				_mMatrix[i][j] = 0;
			}
		}
	}

	SetColumns(columns);
	SetRows(rows);

    return _mMatrix;
}

void ZShape::Rotate()
{
}