#ifndef ISHAPE_H
#define ISHAPE_H

#include "Shape.h"

class IShape : public Shape
{
public:
    IShape() {};
    virtual ~IShape() {};
    virtual bool Create();
    virtual void Rotate(Shape& shape);
};

#endif // !ISHAPE_H
