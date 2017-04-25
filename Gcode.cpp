/*
 * Gcode.cpp
 *
 *  Created on: 25 Apr 2017
 *      Author: williambagshaw
 */


#include "Gcode.h"

static bool IsFigure(char a)
{
	return ((a >= '0') && (a <= '9'));
}

Gcode::Gcode(): m_x{0}, m_y{0}, m_down{false}
{
	for(int i = 0; i < 100;i++)
	{
		enabled[i] = false;
	}
}

bool Gcode::CommandG(char * command, int &i)
{
	i++;
	int code = 0;
	bool change = false;
	while(IsFigure(command[i]))
	{
		code = (code * 10) + (command[i] - '0');
		i++;
	}
	if(command[i] == ' ')
	{
		i++;
	}
	switch(code)
	{
	case 54:
	case 90:
	case 98: // Return to initial Z level ?
	case 21: // Units are mm
		enabled[code] = true;
		break;

	}

	return change;
}

bool Gcode::Command(char * command)
{
	int i = 0;
	bool change = false;
	while(command[i] != '0')
	{
		switch(command[i])
		{
		case '\0':
		case '(':
		case '%':
		case 'o':
		case 'O':
			return change;
		case 'N':
			i++;
			while(IsFigure(command[i]))
			{
				i++;
			}
			if(command[i] == ' ')
			{
				i++;
			}
			break;
		case 'G':
		case 'g':
			change |= CommandG(command,i);
			break;
		case 'T':
		case 't':
			change |= CommandT(command,i);
			break;
		}
	}
 return change;
}
