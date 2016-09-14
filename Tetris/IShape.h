#ifndef ISHAPE_H
#define ISHAPE_H

#include "Shape.h"

class IShape : public Shape
{
public:
    const int COLUMNS = 5;
    const int ROWS = 4;

    IShape();
    virtual ~IShape() {};
    virtual bool** Create();
    virtual void Rotate();
    virtual void MoveDown();
    virtual void MoveUp();
    virtual void MoveRight();
    virtual void MoveLeft();

    virtual const int GetColumns() { return COLUMNS; }
    virtual const int GetRows() { return ROWS; }
    virtual bool** GetMatrix() { return _mMatrix; };
    virtual signed int* GetPosition() { return _mPosition; };

    virtual void SetPosition(signed int* position) { _mPosition = position; };

private:
    const int MIDDLE_COLUMN_NUM = 2;
};

#endif // !ISHAPE_H
