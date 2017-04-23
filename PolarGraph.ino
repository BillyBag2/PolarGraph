#include "compile.h"
#include "Hardware.h"
#include "InterpolateRadii.h"
#include "Coordinates.h"

#ifdef COMPILE_IN_ONE_FILE
#define COMPILE_THIS
#include "Coordinates.cpp"
#include "InterpolateRadii.cpp"
#include "Interpolate.cpp"
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  InterpolateRadii intertpolate(0, 0, 1000, 1000, DISTANCE_BETWEEN_MOTORS_STEPS, COG_RADIUS_STEPS, MINIMUM_LINE_LENGTH);
  const Index count = intertpolate.NumberOfValues();
  for (Index i = 0; i < count; i++)
  {
    Serial.print(intertpolate.R1(i));
    Serial.print(" ");
    Serial.println(intertpolate.R2(i));
  }
  Serial.println("---------------------------");
  Coordinates c(0, 0, DISTANCE_BETWEEN_MOTORS_STEPS, COG_RADIUS_STEPS);
  Serial.print(c.R1());
  Serial.print(" ");
  Serial.println(c.R2());
}
