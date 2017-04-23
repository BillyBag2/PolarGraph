/*
 * StepperFourPhaseFiveWire.cpp
 *
 *  Created on: 23 Apr 2017
 *      Author: williambagshaw
 */

#include "StepperFourPhaseFiveWire.h"



StepperFourPhaseFiveWire::StepperFourPhaseFiveWire
		(
			Pin p1,
			Pin p2,
			Pin p3,
			Pin p4,
			StepperFourPhaseFiveWire::Mode mode
		):m_target{0},m_position{0},m_mode{mode},m_pins{p1,p2,p3,p4},m_step{0}
{

}

void StepperFourPhaseFiveWire::SetPosition(Coordinate p)
{
	m_position = p;
	m_target = p;
	//m_step is unchanged.
}

void StepperFourPhaseFiveWire::Update(void)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		Write(m_pins[i],m_modes[m_mode][m_step][i]);
	}
}

void StepperFourPhaseFiveWire::BreakOff(void)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		Write(m_pins[i],false);
	}
}

void StepperFourPhaseFiveWire::BreakOn(void)
{
	Update();
}

bool StepperFourPhaseFiveWire::Step(void)
{
	if(m_target > m_position)
	{
		// Forward step.
		m_step++;
		if(m_step >= NUM_STEPS)
		{
			m_step = 0;
		}
		m_position++;
		Update();
	}
	else if(m_target < m_position)
	{
		// Backward step.
		m_step--;
		if(m_step < 0)
		{
			m_step = NUM_STEPS - 1;
		}
		m_position--;
		Update();

	}
	return (m_target != m_position);
}
