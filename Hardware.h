

#ifndef _HARWARE_H_
#define _HARWARE_H_

// Motors are assumed to be horizontal.
// DISTANCE_BETWEEN_MOTORS_STEPS is the distance between thier centers.
#define DISTANCE_BETWEEN_MOTORS_STEPS 10000L

// COG_RADIUS_STEPS is the effective radious of the cog.
#define COG_RADIUS_STEPS 100L

// MINIMUM_LINE_LENGTH is an approximate guied to how long a length should be drawn using linearly iterpolated steps.
// It is unlikly to be used exactly but is likly to be within root two of this value. 
#define MINIMUM_LINE_LENGTH 100L

#endif
