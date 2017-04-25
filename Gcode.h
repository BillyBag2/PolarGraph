/*
 * Gcode.h
 *
 *  Created on: 25 Apr 2017
 *      Author: williambagshaw
 */

#ifndef GCODE_H_
#define GCODE_H_

#include "Coordinate.h"

class Gcode
{
public:
	Gcode();
	bool Command(char * command); // Return true if state changed by command.
	Coordinate X(void);
	Coordinate Y(void);
	bool Down(void);

private:
	Coordinate m_x;
	Coordinate m_y;
	bool m_down;
	bool enabled[100];
	bool CommandG(char * command, int &i);
	bool CommandT(char * command, int &i);
};



#endif /* GCODE_H_ */
