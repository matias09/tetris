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
    virtual const int GetRedVal() { return RED_VAL; }
    virtual const int GetGreenVal() { return GREEN_VAL; }
    virtual const int GetBlueVal() { return BLUE_VAL; }
    virtual bool** GetMatrix() { return _mMatrix; };

	// Set
    virtual void SetColumns(unsigned short int columns) { _mColumns = columns; }
    virtual void SetRows(unsigned short int rows) { _mRows = rows; }

    const int RED_VAL = 0x20;
    const int GREEN_VAL = 0x80;
    const int BLUE_VAL = 0xba;
};

#endif // !ZSHAPE_H


