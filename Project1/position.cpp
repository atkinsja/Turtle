/**************************************************************************************************
*
*   File name :			position.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementations of the functions in position.h
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
***************************************************************************************************/
#include "position.h"
/*******************************************************************************************
*	Function Name:			Position() - the constructor
*	Purpose:				Constructor for the Position class. Default position set to 0, 0
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Position::Position()
{
	posX = 0; 
	posY = 0;
}

/*******************************************************************************************
*	Function Name:			setPosX
*	Purpose:				Sets the x position
*	Input Parameters:		int newPosX - the value to set the x position to
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Position::setPosX(int newPosX)
{
	posX = newPosX;
}

/*******************************************************************************************
*	Function Name:			setPosY
*	Purpose:				Sets the y position
*	Input Parameters:		int newPosY - the value to set the y position to
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Position::setPosY(int newPosY)
{
	posY = newPosY;
}

/*******************************************************************************************
*	Function Name:			getPosX
*	Purpose:				Gets the x position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the current x value
********************************************************************************************/
int Position::getPosX()
{
	return posX;
}

/*******************************************************************************************
*	Function Name:			getPosY
*	Purpose:				Gets the y position
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			int - the current y value
********************************************************************************************/
int Position::getPosY()
{
	return posY;
}