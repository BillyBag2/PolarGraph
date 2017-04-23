#ifndef _STEPPERFOURPHASEFIVEWIRE_H_
#define _STEPPERFOURPHASEFIVEWIRE_H_

/*
 * StepperFourPhaseFiveWire.h
 *
 *  Created on: 23 Apr 2017
 *      Author: williambagshaw
 */
#include "Coordinate.h"
#include "IStepper.h"

typedef int Pin;

class StepperFourPhaseFiveWire: public IStepper
{
public:
	typedef enum {WAVE, STEP, HALF_STEP} Mode;
	StepperFourPhaseFiveWire(Pin p1, Pin p2, Pin p3, Pin p4, Mode mode);
	virtual ~StepperFourPhaseFiveWire();

	virtual void SetPosition(Coordinate position);
	virtual void SetTarget(Coordinate target);
	virtual bool Step(void);
	void BreakOff(void);
	void BreakOn(void);

private:
	virtual void Write(Pin p, bool state) = 0;
	virtual void Update(void);
	Coordinate m_target;
	Coordinate m_position;
	Mode m_mode;
	Pin m_pins[4];
	int m_step;
	enum { NUM_STEPS = 8 };
	const bool m_modes[3][8][4] =
			{
					// WAVE (Two laps.)
					{
							{ true, false, false, false },
							{ false, true, false, false },
							{ false, false, true, false },
							{ false, false, false, true },
							{ true, false, false, false },
							{ false, true, false, false },
							{ false, false, true, false },
							{ false, false, false, true },
					},
					// STEP (Two laps.)
					{
							{ true, true, false, false },
							{ false, true, true, false },
							{ false, false, true, true },
							{ true, false, false, true },
							{ true, true, false, false },
							{ false, true, true, false },
							{ false, false, true, true },
							{ true, false, false, true },
					},
					// HALF_STEP  (One lap.)
					{
							{ true, true, false, false },
							{ false, true, false, false },
							{ false, true, true, false },
							{ false, false, true, false },
							{ false, false, true, true },
							{ false, false, false, true },
							{ true, false, false, true },
							{ true, false, false, false },
					}
			};
};
#endif
