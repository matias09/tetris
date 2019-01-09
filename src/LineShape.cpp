#include "LineShape.h"

LineShape::LineShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }

	_mRotateTo = 2;
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
    _RotateToUp();
    return _mMatrix;
}

void LineShape::_RotateToUp()
{
	_mRows = 4;
	_mColumns = 1;

	for (unsigned short int i = 0; i < _mRows; i++)
	{
		_mMatrix[i][0] = 1;
	}

	SetColumns(_mColumns);
	SetRows(_mRows);
}

void LineShape::_RotateToLeft()
{
	_mRows = 1;
	_mColumns = 4;

	for (unsigned short int j = 0; j < _mColumns; j++)
	{
		_mMatrix[0][j] = 1;
	}

	SetColumns(_mColumns);
	SetRows(_mRows);
}
