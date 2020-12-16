#include "turtle.h"
#include <iostream>
/*******************************************************************************************
*	Function Name:			Turtle() - the constructor
*	Purpose:				Constructor for the Turtle class. Constructs Position, Direction,
*							and Pen classes for the Turtle. Initializes the previous position
							to 0, 0
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Turtle::Turtle()
{
	pos = new Position;
	direction = new Direction;
	pen = new Pen;
	previousX = 0;
	previousY = 0;
}

/*******************************************************************************************
*	Function Name:			~Turtle() - the destructor
*	Purpose:				Destructor for the Position class. Deallocates memory for the
*							constructed Pen, Position, and Direction classes and sets
*							the values for them to NULL
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Turtle::~Turtle()
{
	delete pos;
	pos = NULL;

	delete pen;
	pen = NULL;

	delete direction;
	direction = NULL;
}

/*******************************************************************************************
*	Function Name:			getCurrentX
*	Purpose:				Gets the current x position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the current x value
********************************************************************************************/
int Turtle::getCurrentX()
{
	return pos->getPosX();
}

/*******************************************************************************************
*	Function Name:			getCurrentY
*	Purpose:				Gets the current y position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the current y value
********************************************************************************************/
int Turtle::getCurrentY()
{
	return pos->getPosY();
}

/*******************************************************************************************
*	Function Name:			getPreviousX
*	Purpose:				Gets the previous x position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the previous x value
********************************************************************************************/
int Turtle::getPreviousX()
{
	return previousX;
}

/*******************************************************************************************
*	Function Name:			getPreviousY
*	Purpose:				Gets the previous y position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the current y value
********************************************************************************************/
int Turtle::getPreviousY()
{
	return previousY;
}

/*******************************************************************************************
*	Function Name:			move
*	Purpose:				Changes the turtles position according to the direction and
*							the number of spaces to be moved
*	Input Parameters:		int numSpaces - the number of spaces to move
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::move(int numSpaces)
{
	//updates previous X and Y values
	previousX = getCurrentX();
	previousY = getCurrentY();
	
	//moves the turtle depending on the direction the turtle is facing
	switch (direction->getDir())
	{
	case 's':
		pos->setPosY(getCurrentY() + numSpaces);
		break;
	case 'n':
		pos->setPosY(getCurrentY() - numSpaces);
		break;
	case 'w':
		pos->setPosX(getCurrentX() - numSpaces);
		break;
	case 'e':
		pos->setPosX(getCurrentX() + numSpaces);
		break;
	}
	
}

/*******************************************************************************************
*	Function Name:			turn
*	Purpose:				Changes the turtles direction
*	Input Parameters:		char dir - the direction to turn the turtle in
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::turn(char dir)
{
	direction->changeDir(dir);		
}
	
/*******************************************************************************************
*	Function Name:			jump
*	Purpose:				Moves the turtle to any new position without drawing
*	Input Parameters:		int newX - the new X position
							int newY - the new Y position
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::jump(int newX, int newY)
{
	setCurrentX(newX);
	setCurrentY(newY);
}

/*******************************************************************************************
*	Function Name:			setCurrentX
*	Purpose:				Sets the current X position
*	Input Parameters:		int newX - the value to set the x value to
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::setCurrentX(int newX)
{
	pos->setPosX(newX);
}

/*******************************************************************************************
*	Function Name:			setCurrentY
*	Purpose:				Sets the current Y position
*	Input Parameters:		int newY - the value to set the y value to
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::setCurrentY(int newY)
{
	pos->setPosY(newY);
}

/*******************************************************************************************
*	Function Name:			changePenPosition
*	Purpose:				Toggles the pen up or down
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Turtle::changePenPosition()
{
	pen->togglePenPosition();
}

/*******************************************************************************************
*	Function Name:			penDown
*	Purpose:				Checks whether the pen is up or down
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			bool - a flag true of the pen is down, false if the pen is up
********************************************************************************************/
bool Turtle::penDown()
{
	return pen->getPenPosition();
}

/*******************************************************************************************
*	Function Name:			changeBrush
*	Purpose:				changes the current brush selection
*	Input Parameters:		int brush - the brush to be selected
*	Output Parameters:		none
*	Return value:			char - the character of the brush
********************************************************************************************/
char Turtle::changeBrush(int brush)
{	
	return pen->getBrush(brush);
}

/*******************************************************************************************
*	Function Name:			getDirection
*	Purpose:				Gets the current direction of the turtle
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			char - the direction the turtle is facing
********************************************************************************************/
char Turtle::getDirection()
{
	return direction->getDir();
}

