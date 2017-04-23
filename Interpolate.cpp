#include "compile.h"
#ifdef COMPILE_THIS
#include <arduino.h>
#include "Coordinate.h"
#include "Interpolate.h"

Interpolate::Interpolate(
  Coordinate x1,
  Coordinate y1,
  Coordinate x2,
  Coordinate y2,
  Coordinate maxStep):
  m_x1(x1),
  m_x2(x2),
  m_y1(y1),
  m_y2(y2)
{
  // Find the bigest delta.
  Coordinate diffMax = abs(x2 - x1);
  Coordinate diffY = abs(y2 - y1);
  if (diffY > diffMax)
  {
    diffMax = diffY;
  }
  // Calculate number of values
  m_numberOfValues = (diffMax / maxStep) + 1;

  // We need at least a beginning and an end.
  // (Give two pionts even if start = end ?)
  if (m_numberOfValues < 2)
  {
    m_numberOfValues = 2;
  }

}
Index Interpolate::NumberOfValues()
{
  return m_numberOfValues;
}

Coordinate Interpolate::X(Index index)
{
  return m_x1 + ((index * (m_x2 - m_x1))/(m_numberOfValues - 1));
}

Coordinate Interpolate::Y(Index index)
{
  return m_y1 + ((index * (m_y2 - m_y1))/(m_numberOfValues - 1));
}
#endif
