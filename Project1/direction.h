/**************************************************************************************************
*
*   File name :			direction.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Direction class, implemented in direction.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
*
*	Class Name:		Direction
*
*	Private data members:
*		char dir - the current direction
*
*	Public member functions:
*		Direction() - Constructor for a Direction object
*		changeDir - changes the current direction
*		getDir - returns the current direction
****************************************************************************************************/
#ifndef DIRECTION_H
#define DIRECTION_H

class Direction
{
public:
	Direction();
	void changeDir(char);
	char getDir();

private:
	char dir;
};

#endif