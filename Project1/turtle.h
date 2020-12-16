
#ifndef TURTLE_H
#define TURTLE_H
/**************************************************************************************************
*
*   File name :			turtle.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Turtle class, implemented in turtle.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
*
*	Class Name:		Turtle
*
*	Private data members:
*		pos - a pointer to a Position class
*		pen - a pointer to a Pen class
*		direction - a pointer to a Direction class
*		previousX - the previous X position of the turtle
*		previousY - the previous Y position of the turtle
*
*	Public member functions:
*		Turtle() - constructor for a Turtle object
*		~Turtle() - destructor for a Turtle object
*		getCurrentX - gets the current x position
*		getCurrentY - gets the current y position
*		getPreviousX - gets the previous x position
*		getPreviousY - gets the previous y position
*		setCurrentX - sets the current x position
*		setCurrentY - sets the current y position
*		getDirection - gets the current direction
*		move - changes the turtle position based on the number of spaces to move
*		turn - changes the turtle's direction
*		jump - changes the turtle's x, y position
*		changeBrush - changes the brush the turtle draws with
*		changePenPosition - toggles the pen up or down
*		penDown - checks whether the pen is down or not
****************************************************************************************************/
#include "position.h"
#include "pen.h"
#include "direction.h"
class Turtle
{
public:
	Turtle();
	~Turtle();
	int getCurrentX();
	int getCurrentY();
	int getPreviousX();
	int getPreviousY();
	void setCurrentX(int);
	void setCurrentY(int);
	char getDirection();
	void move(int);
	void turn(char);
	void jump(int, int);
	char changeBrush(int);
	void changePenPosition();
	bool penDown();
private:
	Position* pos;
	Pen* pen;
	Direction* direction;
	int previousX, previousY;

};
#endif
