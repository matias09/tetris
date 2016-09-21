#ifndef LINE_SHAPE_H
#define LINE_SHAPE_H

#include "Shape.h"

class LineShape : public Shape
{
public:
    LineShape();
    virtual ~LineShape();
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

#endif // !LINE_SHAPE_H
