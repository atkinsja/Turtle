/**************************************************************************************************
*
*   File name :			pen.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Pen class, implemented in pen.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
*
*	Class Name:		Pen
*
*	Private data members:
*		bool isDown - true of pen is down, false if pen is up
*		char drawChar - the character to be drawn
*
*	Public member functions:
*		Pen() - Constructor for a Pen object
*		togglePenPosition - sets the pen up or down
*		getPenPosition - returns whether the pen is up or down
*		getBrush - returns the brush to draw with
****************************************************************************************************/
#ifndef PEN_H
#define PEN_H

class Pen
{
public:
	Pen();
	void togglePenPosition();
	bool getPenPosition();
	char getBrush(int);
	
private:
	bool isDown;
	char drawChar;

};

#endif