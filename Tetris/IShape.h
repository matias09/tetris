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
    virtual void MoveDown();
    virtual void MoveUp();
    virtual void MoveRight();
    virtual void MoveLeft();

    virtual const int GetColumns() { return 1; }
    virtual const int GetRows() { return 4; }
    virtual bool** GetMatrix() { return _mMatrix; };
    virtual signed int* GetPosition() { return _mPosition; };

    virtual void SetPosition(signed int* position) { _mPosition = position; };
};

#endif // !ISHAPE_H
