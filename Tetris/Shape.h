#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() {};
    virtual bool** Create() = 0;
    virtual void Rotate() = 0;
    virtual void MoveDown() = 0;
    virtual void MoveUp() = 0;
    virtual void MoveRight() = 0;
    virtual void MoveLeft() = 0;

    virtual const int GetColumns() = 0;
    virtual const int GetRows() = 0;
    virtual bool** GetMatrix() = 0;
    virtual signed int* GetPosition() = 0;

    virtual void SetPosition(signed int* position) = 0;

    const int COORDINATE_ELEMENTS = 2;
	const int X_COORDINATE = 0;
    const int Y_COORDINATE = 1;

    signed int* _mPosition;
    bool** _mMatrix;
};
#endif // !SHAPE_H
