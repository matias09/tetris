#ifndef JSHAPE_H
#define JSHAPE_H

#include "Shape.h"

class JShape : public Shape
{
public:
    JShape();
    virtual ~JShape();
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

    const int RED_VAL = 0xd3;
    const int GREEN_VAL = 0xdf;
    const int BLUE_VAL = 0x11;
};

#endif // !JSHAPE_H
