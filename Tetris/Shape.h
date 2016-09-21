#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() {};
    virtual bool** Create() = 0;
	virtual void Rotate() = 0;

	// Get
	virtual unsigned short int GetColumns() = 0;
    virtual unsigned short int GetRows() = 0;
    virtual const int GetColorMod() = 0;
    virtual bool** GetMatrix() = 0;

	// Set
    virtual void SetColumns(unsigned short int columns) = 0;
    virtual void SetRows(unsigned short int rows) = 0;

    const int SHAPE_DIMENSION = 4;

	unsigned short int _mRows;
	unsigned short int _mColumns;
	unsigned short int _mRotateState;
    bool** _mMatrix;
};
#endif // !SHAPE_H
