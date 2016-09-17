#ifndef ISHAPE_H
#define ISHAPE_H

#include "Shape.h"

class IShape : public Shape
{
public:
    IShape();
    virtual ~IShape() {};
    virtual bool** Create();
    virtual void Rotate();
    virtual void MoveDown(signed int position[], const int coordinate);
    virtual void MoveUp(signed int position[], const int coordinate);
    virtual void MoveRight(signed int position[], const int coordinate);
    virtual void MoveLeft(signed int position[], const int coordinate);

	// Get
    virtual const int GetColumns() { return SHAPE_DIMENSION; }
    virtual const int GetRows() { return SHAPE_DIMENSION; }
    virtual const int GetColorMod() { return COLOR_MODIFICATOR; }
    virtual bool** GetMatrix() { return _mMatrix; };

    const int COLOR_MODIFICATOR = 0xfa;
};

#endif // !ISHAPE_H
