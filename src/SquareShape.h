#ifndef SQUARE_SHAPE_H
#define SQUARE_SHAPE_H

#include "Shape.h"

class SquareShape : public Shape
{
public:
  SquareShape();
  virtual ~SquareShape();
  virtual bool** Create();

  // Get
  virtual unsigned short int GetColumns() { return _mColumns; }
  virtual unsigned short int GetRows() { return _mRows; }
  virtual unsigned short int* GetGyreCoordinate() { return _mGyreCoordinate; }
  virtual unsigned short int GetActualRotation() { return _mRotateTo; }
  virtual const int GetRedVal() { return RED_VAL; }
  virtual const int GetGreenVal() { return GREEN_VAL; }
  virtual const int GetBlueVal() { return BLUE_VAL; }
  virtual bool** GetMatrix() { return _mMatrix; };

  // Set
  virtual void SetColumns(unsigned short int columns) { _mColumns = columns; }
  virtual void SetRows(unsigned short int rows) { _mRows = rows; }
  virtual void SetGyreCoordinate(unsigned short int* newGyreCoordinate) 
  { 
    _mGyreCoordinate = newGyreCoordinate; 
  }
  virtual void SetActualRotation(unsigned short int rotation) 
  { 
    _mRotateTo = rotation; 
  }

  const int RED_VAL = 0x10;
  const int GREEN_VAL = 0x40;
  const int BLUE_VAL = 0xaa;

private:
  virtual void _RotateToUp() {}
  virtual void _RotateToLeft() {}
  virtual void _RotateToDown() {}
  virtual void _RotateToRight() {}
};

#endif // !SQUARE_SHAPE_H
