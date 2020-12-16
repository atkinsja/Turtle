/**************************************************************************************************
*
*   File name :			direction.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementations of the functions in direction.h
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
***************************************************************************************************/
#include "direction.h"
/*******************************************************************************************
*	Function Name:			Direction() - the constructor
*	Purpose:				Constructor for the Direction class. Default direction set to east
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Direction::Direction()
{
	dir = 'e';
}
/*******************************************************************************************
*	Function Name:			setDir
*	Purpose:				Sets the direction
*	Input Parameters:		char newDir - the value to set the direction to
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Direction::changeDir(char newDir)
{
	
	if (newDir == dir)
		return;
	else
		dir = newDir;
}

/*******************************************************************************************
*	Function Name:			getDir
*	Purpose:				Gets the direction
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			char - the current direction
********************************************************************************************/
char Direction::getDir()
{
	return dir;
}