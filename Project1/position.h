
/**************************************************************************************************
*
*   File name :			position.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Position class, implemented in position.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
*
*	Class Name:		Position
*
*	Private data members:
*		int posX - current X Value
*		int posY - current Y Value
*
*	Public member functions:
*		Position() - Constructor for a Position object
*		setPosX - sets a new x position
*		setPosY - sets a new y position
*		getPosX - returns the current x position
*		getPosY - returns the current y position
****************************************************************************************************/
#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	Position();
	void setPosX(int);
	void setPosY(int);
	int getPosX();
	int getPosY();
private:
	int posX, posY;
	
	
};
#endif