#ifndef _ISTEPPER_H_
#define _ISTEPPER_H_
/*
 * IStepper.h
 *
 *  Created on: 23 Apr 2017
 *      Author: williambagshaw
 */
#include "Coordinate.h"

class IStepper
{
public:
	IStepper();
	virtual void SetPosition(Coordinate position) = 0;  // Set the target and the current position to the value supplied.
	virtual void SetTarget(Coordinate target) = 0; 		// The target to aim for.
	virtual bool Step(void) = 0;						// Perform a step towards target. Return False if reached.
	virtual void Stop(void) = 0;						// Stop stepping by setting the target to the current position.
	virtual void BreakOff(void) = 0;					// Set a mode were the motor is not held.
	virtual void BreakOn(void) = 0;					    // Hold the motor in its current position.
	virtual ~IStepper();
};

#endif
