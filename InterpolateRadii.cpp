#include "compile.h"
#ifdef COMPILE_THIS
#include "InterpolateRadii.h"
#include "Coordinates.h"

InterpolateRadii::InterpolateRadii(
  Coordinate x1,
  Coordinate y1,
  Coordinate x2,
  Coordinate y2,
  Coordinate DistanceBetweenMotors, // Distance between the center of the motor shafts.
  Coordinate CogRadious,
  Coordinate maxStep) :
  Interpolate(x1, y1, x2, y2, maxStep),
  m_d(DistanceBetweenMotors),
  m_r(CogRadious)
{

};

Coordinate InterpolateRadii::R1(Index i)
{
  Coordinates c(X(i), Y(i), m_d, m_r);
  return c.R1();
}
Coordinate InterpolateRadii::R2(Index i)
{
  Coordinates c(X(i), Y(i), m_d, m_r);
  return c.R2();
}
#endif
