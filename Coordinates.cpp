#include "compile.h"
#ifdef COMPILE_THIS

#include <Arduino.h>
#include "Coordinates.h"


Coordinates::Coordinates(
  Coordinate x,
  Coordinate y,
  Coordinate DistanceBetweenMotors,
  Coordinate CogRadious):
  m_x(x),
  m_y(y),
  m_d(DistanceBetweenMotors),
  m_r(CogRadious)

{

}
CoordinateSq Coordinates::Square(Coordinate x)
{
  CoordinateSq v = (CoordinateSq)x;
  return v * v;
}

Coordinate Coordinates::R1(void)
{
  return sqrt(Square(m_x) + Square(m_y));
}

Coordinate Coordinates::R2(void)
{
  Coordinate fromMotor2 = m_d - m_x;
  return sqrt(Square(fromMotor2) + Square(m_y));
}

#endif
