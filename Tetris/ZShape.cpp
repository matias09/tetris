#include "ZShape.h"

ZShape::ZShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }

	_mRotateTo = 2;
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
    _RotateToUp();
    return _mMatrix;
}

void ZShape::Rotate()
{
    switch (_mRotateTo)
    {
    case 1:
        _RotateToLeft();
    break;
    case 2:
        _mRotateTo = 0;
        _RotateToUp();
    break;
    }

    _mRotateTo++;
}

void ZShape::_RotateToUp()
{
	_mRows = 2;
	_mColumns = 3;

	for (unsigned short int i = 0; i < _mRows; i++)
	{
		for (unsigned short int j = 0; j < _mColumns; j++)
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

	SetColumns(_mColumns);
	SetRows(_mRows);
}

void ZShape::_RotateToLeft()
{
	_mRows = 2;
	_mColumns = 3;

	for (unsigned short int i = 0; i < _mRows; i++)
	{
		for (unsigned short int j = 0; j < _mColumns; j++)
		{
			if (j != 0 && i != 0 && j != 2 && i != 2)
			{
				_mMatrix[i][j] = 1;
			}
			else
			{
				_mMatrix[i][j] = 0;
			}
		}
	}

	SetColumns(_mColumns);
	SetRows(_mRows);
}
