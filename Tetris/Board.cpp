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

void Board::Update(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
    // Check if there any collision
    bool thereIsCollision = _ThereIsCollision(shape, shapePos, shapeColumns, shapeRows);
	
	if (thereIsCollision == false)
	{
		_UpdateFigureInBoard(shape, shapePos, shapeColumns, shapeRows);
		_mGrpHandler.Render(_mBoard, COLUMNS, ROWS);
	}
}

void Board::EraseLastPosition(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
    unsigned int xActualPos = shapePos[0];
    unsigned int yActualPos = shapePos[1];

	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			_mBoard[yActualPos][xActualPos++] = 0;
		}

		// Esto va corriendo la posicion en Y
		yActualPos++;

		// Reseteo X para que comience desde el principio de la row
        xActualPos = shapePos[0];
    }
}

void Board::_UpdateFigureInBoard(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
    unsigned int xActualPos = shapePos[0];
    unsigned int yActualPos = shapePos[1];

	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			_mBoard[yActualPos][xActualPos++] = shape[i][j];
		}

		// Esto va corriendo la posicion en Y
		yActualPos++;

		// Reseteo X para que comience desde el principio de la row
        xActualPos = shapePos[0];
    }
}

bool Board::_ThereIsCollision(bool** shape, int* shapePos, const int shapeColumns, const int shapeRows)
{
	// TODO :: Hay que actualizar el array de posiciones en las clases Shape.
	//  para que no siga modificando su posicion, En este momento, valida si se esta 
	//  por pasar de los limites del board, pero como no se esta corrigiendo el array
	//  que maneja la posicion actual de la figura, en el siguiente chequeo estalla,
	//  porque en el tablero se ve una cosa y en la logica del juego hay otra.

	// Daniel, si estas leyendo esto, POR FAVOR no me digas como solucionarlo.

	bool collision = false;
    unsigned int xActualPos = shapePos[0];
    unsigned int yActualPos = shapePos[1];

	for (int i = 0; i < shapeRows; i++)
	{
		for (int j = 0; j < shapeColumns; j++)
		{
			if ((xActualPos == -1 || yActualPos == (COLUMNS + 1))
				|| (yActualPos == -1 || yActualPos == (ROWS + 1))
				|| _mBoard[yActualPos][xActualPos] != 0
			) {
				collision = true;
				i = shapeRows;
				break;
			}

			xActualPos++;
		}

		// Esto va corriendo la posicion en Y
		yActualPos++;

		// Reseteo X para que comience desde el principio de la row
        xActualPos = shapePos[0];
    }
    return collision;
}
