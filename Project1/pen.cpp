/**************************************************************************************************
*
*   File name :			pen.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementations of the functions in pen.h
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
***************************************************************************************************/
#include "pen.h"

/*******************************************************************************************
*	Function Name:			Pen() - the constructor
*	Purpose:				Constructor for the Pen class. Default values with the pen 
*							toggled up and the draw character initialized to 'O'
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Pen::Pen()
{
	isDown = false;
	drawChar = 'O';
}

/*******************************************************************************************
*	Function Name:			togglePenPosition
*	Purpose:				If the pen is up, set it down, if the pen is down, set it up
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Pen::togglePenPosition()
{
	if (!isDown)
		isDown = true;
	else
		isDown = false;
}

/*******************************************************************************************
*	Function Name:			getPenPosition
*	Purpose:				Returns true if the pen is down or false if the pen is up
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			bool toggle for the pen position
********************************************************************************************/
bool Pen::getPenPosition()
{
	return isDown;
}

/*******************************************************************************************
*	Function Name:			getBrush
*	Purpose:				Selects a brush depending on user input
*	Input Parameters:		selection - the brush chosen by the user
*	Output Parameters:		none
*	Return value:			char - the character to draw with, or the character 1 if the 
*							selection is an invalid selection
********************************************************************************************/
char Pen::getBrush(int selection)
{
	switch (selection)
	{
	case 1:
		drawChar = 'O';
		break;
	case 2:
		drawChar = '*';
		break;
	case 3:
		drawChar = '&';
		break;
	case 4:
		drawChar = '%';
		break;
	default:
		return '1';
	}
	return drawChar;
}

