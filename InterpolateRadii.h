#ifndef _INTERPOLATERADII_H_
#define _INTERPOLATERADII_H_
#include "Interpolate.h"
#include "Coordinate.h"

class InterpolateRadii: public Interpolate
{
  public:
    InterpolateRadii(Coordinate x1,
                     Coordinate y1,
                     Coordinate x2,
                     Coordinate y2,
                     Coordinate DistanceBetweenMotors, // Distance beween the center of the motor shafts.
                     Coordinate CogRadious,
                     Coordinate maxStep);
    Coordinate R1(Index i);
    Coordinate R2(Index i);
    private:
    Coordinate m_d;
    Coordinate m_r;
};
#endif
