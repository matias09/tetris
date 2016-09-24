#include "SquareShape.h"

SquareShape::SquareShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }

	_mRotateTo = 2;
}

SquareShape::~SquareShape()
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

bool** SquareShape::Create()
{
	unsigned short int columns = 2;
	unsigned short int rows = 2;

	for (unsigned short int i = 0; i < rows; i++)
	{
		for (unsigned short int j = 0; j < columns; j++)
		{
			_mMatrix[i][j] = 1;
		}
	}

	SetColumns(columns);
	SetRows(rows);

    return _mMatrix;
}