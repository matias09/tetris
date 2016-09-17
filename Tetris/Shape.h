#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() {};
    virtual bool** Create() = 0;
    virtual void Rotate() = 0;
    virtual void MoveDown(signed int position[], const int coordinate) = 0;
    virtual void MoveUp(signed int position[], const int coordinate) = 0;
    virtual void MoveRight(signed int position[], const int coordinate) = 0;
    virtual void MoveLeft(signed int position[], const int coordinate) = 0;

    virtual const int GetColumns() = 0;
    virtual const int GetRows() = 0;
    virtual const int GetColorMod() = 0;
    virtual bool** GetMatrix() = 0;

    const int SHAPE_DIMENSION = 4;

    bool** _mMatrix;
};
#endif // !SHAPE_H
