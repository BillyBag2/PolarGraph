
#ifndef _COORDINATES_H_
#define _COORDINATES_H_

#include "Coordinate.h"

// Note that this class is unit-less.

class Coordinates
{
  public:
    Coordinates(
      Coordinate x,                     // Measured from the left motor horizontally to the right.
      Coordinate y,                     // Measured from horizontal line of the motors down. (Yes, Downwards)
      Coordinate DistanceBetweenMotors, // Distance beween the center of the motor shafts.
      Coordinate CogRadious);           // Effective Radius of the cog. (At time of writing this was ignored by the calculation.)

    Coordinate R1(void);  // Desired new radius for first motor.
    Coordinate R2(void);  // Desired new radius for second motor.
  private:
    Coordinate m_x;
    Coordinate m_y;
    Coordinate m_d;
    Coordinate m_r;
    static CoordinateSq Square(Coordinate);
};
#endif
