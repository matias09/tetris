#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
  virtual ~Shape() {};
  virtual bool** Create() = 0;
  virtual void _RotateToUp() = 0;
  virtual void _RotateToLeft() = 0;
  virtual void _RotateToDown() = 0;
  virtual void _RotateToRight() = 0;

  // Get
  virtual unsigned short int GetColumns() = 0;
  virtual unsigned short int GetRows() = 0;
  virtual unsigned short int* GetGyreCoordinate() = 0;
  virtual unsigned short int GetActualRotation() = 0;
  virtual const int GetRedVal() = 0;
  virtual const int GetGreenVal() = 0;
  virtual const int GetBlueVal()  = 0;
  virtual bool** GetMatrix() = 0;

  // Set
  virtual void SetColumns(unsigned short int columns) = 0;
  virtual void SetRows(unsigned short int rows) = 0;
  virtual void SetGyreCoordinate(unsigned short int* newGyreCoordinate) = 0;
  virtual void SetActualRotation(unsigned short int rotation) = 0;

  const unsigned short int SHAPE_DIMENSION = 4;
  const unsigned short int COORDINATE_ELEMENTS = 2;
  const unsigned short int X_COORDINATE = 0;
  const unsigned short int Y_COORDINATE = 1;

  unsigned short int _mRows;
  unsigned short int _mColumns;
  unsigned short int _mRotateTo;
  unsigned short int *_mGyreCoordinate;
  bool **_mMatrix;
};
#endif // !SHAPE_H
