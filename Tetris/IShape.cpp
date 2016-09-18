#include "IShape.h"

IShape::IShape()
{
    _mMatrix = new bool*[SHAPE_DIMENSION];
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        _mMatrix[i] = new bool[SHAPE_DIMENSION];
    }
}

IShape::~IShape()
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

bool** IShape::Create()
{
    for (int i = 0; i < SHAPE_DIMENSION; i++)
    {
        for (int j = 0; j < SHAPE_DIMENSION; j++)
        {
            if (j == 0)
            {
                _mMatrix[i][j] = 1;
            }
			else
			{
				_mMatrix[i][j] = 0;
			}
        }
    }

    return _mMatrix;
}

void IShape::Rotate()
{}

void IShape::MoveUp(signed int position[], const int coordinate){}

void IShape::MoveDown(signed int position[], const int coordinate)
{
	++position[coordinate];
}

void IShape::MoveRight(signed int position[], const int coordinate)
{
	++position[coordinate];
}

void IShape::MoveLeft(signed int position[], const int coordinate)
{
	--position[coordinate];
}
