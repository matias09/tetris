#include "IShape.h"

IShape::IShape()
{
	// TODO :: Eliminar hardcodeo de indice
    _mMatrix = new bool*[4];
    for (int i = 0; i < 4; i++)
    {
		// TODO :: Eliminar hardcodeo de indice
        _mMatrix[i] = new bool[1];
    }

    _mPosition = new int[COORDINATE_ELEMENTS];
    _mPosition[X_COORDINATE] = 4;
    _mPosition[Y_COORDINATE] = 0;
}

bool** IShape::Create()
{
	// TODO :: Eliminar hardcodeo en i < 1. Debe ir la cantidad de Filas necesarias
    for (int i = 0; i < 4; i++)
    {
		// TODO :: Eliminar hardcodeo en j < 1. Debe ir la cantidad de Columnas necesarias 
        for (int j = 0; j < 1; j++)
        {
            if (j == 0)
            {
                _mMatrix[i][j] = 1;
            }
        }
    }

    return _mMatrix;
}

void IShape::Rotate()
{}

void IShape::MoveDown()
{
	++_mPosition[Y_COORDINATE];
}

void IShape::MoveUp()
{
	--_mPosition[Y_COORDINATE];
}

void IShape::MoveRight()
{
	++_mPosition[X_COORDINATE];
}

void IShape::MoveLeft()
{
	--_mPosition[X_COORDINATE];
}
