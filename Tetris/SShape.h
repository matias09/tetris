#ifndef SSHAPE_H
#define SSHAPE_H

#include "Shape.h"

class SShape : public Shape
{
public:
    SShape();
    virtual ~SShape();
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

    const int RED_VAL = 0x99;
    const int GREEN_VAL = 0xff;
    const int BLUE_VAL = 0xac;
};

#endif // !SSHAPE_H
