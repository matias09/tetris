#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual ~Shape() {};
    virtual bool Create() = 0;
    virtual void Rotate(Shape& shape) = 0;
};
#endif // !SHAPE_H
