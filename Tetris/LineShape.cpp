#include "LineShape.h"

LineShape::LineShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }
}

LineShape::~LineShape()
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

bool** LineShape::Create()
{
	unsigned short int columns = 1;
	unsigned short int rows = 4;

	for (unsigned short int i = 0; i < rows; i++)
	{
		_mMatrix[i][0] = 1;
	}

	SetColumns(columns);
	SetRows(rows);

    return _mMatrix;
}

void LineShape::Rotate()
{
}
