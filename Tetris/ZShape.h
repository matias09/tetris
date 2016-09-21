#ifndef ZSHAPE_H
#define ZSHAPE_H

#include "Shape.h"

class ZShape : public Shape
{
public:
    ZShape();
    virtual ~ZShape();
    virtual bool** Create();
	virtual void Rotate();

	// Get
    virtual unsigned short int GetColumns() { return _mColumns; }
    virtual unsigned short int GetRows() { return _mRows; }
    virtual const int GetColorMod() { return COLOR_MODIFICATOR; }
    virtual bool** GetMatrix() { return _mMatrix; };

	// Set
    virtual void SetColumns(unsigned short int columns) { _mColumns = columns; }
    virtual void SetRows(unsigned short int rows) { _mRows = rows; }

    const int COLOR_MODIFICATOR = 0xfa;
};

#endif // !ZSHAPE_H


