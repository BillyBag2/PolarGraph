
#ifndef _INTERPOLATE_H_
#define _INTERPOLATE_H_

#include "Coordinate.h"

typedef int Index; // Index into the value.

class Interpolate
{
  public:
    Interpolate(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2, Coordinate maxStep);
    Index NumberOfValues(); // The number of values.
    Coordinate X(Index index);
    Coordinate Y(Index index);
  private:
    Index m_numberOfValues;
    Coordinate m_x1;
    Coordinate m_x2;
    Coordinate m_y1;
    Coordinate m_y2;

};

#endif
