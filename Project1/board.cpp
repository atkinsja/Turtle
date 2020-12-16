/**************************************************************************************************
*
*   File name :			board.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Implementation of the functions defined in board.h. 
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
****************************************************************************************************/

#include "board.h"
#include <iostream>
using namespace std;

/*******************************************************************************************
*	Function Name:			Board() - the constructor
*	Purpose:				This constructor creates a 20 x 20 board, allocates memory for
*							a turtle class to be placed on the board, and initializes the 
*							values for the different characters used when drawing the
*							turtle and the board
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Board::Board()
{
	SIZE = 20;
	topCornerLeft = (char)201;
	topCornerRight = (char)187;
	botCornerLeft = (char)200;
	botCornerRight = (char)188;
	vertWall = (char)186;
	horWall = (char)205;
	groundChar = (char)240;
	turtleChar = (char)153;
	floor = new char*[SIZE];
	turtle = new Turtle;
	for (int i = 0; i < SIZE; i++)
		floor[i] = new char[SIZE];
	initBoard(floor);
	drawChar = turtle->changeBrush(1);
}

/*******************************************************************************************
*	Function Name:			~Board() - the destructor
*	Purpose:				This destructor deallocates the memory for the turtle, as well
*							as deallocates all of the memory for the board, setting all of
*							the values to NULL afterward.
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
Board::~Board()
{
	delete turtle;
	turtle = NULL;

	for (int i = 0; i < SIZE; i++)
	{
		delete[] floor[i];
		floor[i] = NULL;
	}
	delete floor;
	floor = NULL;

}

/*******************************************************************************************
*	Function Name:			initBoard
*	Purpose:				This function initializes all of the characters in the board to
*							the default characters to be used to represent the ground
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::initBoard(char** floor)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			floor[i][j] = groundChar;

		}
	}
}

/*******************************************************************************************
*	Function Name:			printBoard
*	Purpose:				Prints a border around the board and all of the board, the turtle
*							character itself based on its position, and any updated tiles
*							caused by the turtle's movement
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::printBoard()
{
	//top border	
	for (int i = 0; i < 3*SIZE+2; i++)
	{
		if (i == 0)
			cout << topCornerLeft;
		else if (i == 3*SIZE+1)
			cout << topCornerRight;
		else
			cout << horWall;
	}
	cout << endl;

	//board
	for (int i = 0; i < SIZE; i++)
	{
		cout << vertWall;		//left wall
		for (int j = 0; j < SIZE; j++)
		{
			//the current tile is the turtle
			if ((turtle->getCurrentY() == i) && (turtle->getCurrentX() == j))
				floor[i][j] = turtleChar;

			//the current tile is not the turtle
			else
			{
				//if the current character has not been drawn over by the turtle, the current tile is the ground character
				if(floor[i][j] != '*' && floor[i][j] != '&' && floor[i][j] != '%' && floor[i][j] != 'O' && drawChar)
					floor[i][j] = groundChar;
			}
			cout <<  " " << floor[i][j] << " ";	//prints the current tile
		}
		cout << vertWall;		//right wall
		if(i != SIZE - 1)
			cout << "\n";
	}
	cout << endl;

	//bottom border
	for (int i = 0; i < 3*SIZE + 2; i++)
	{
		if (i == 0)
			cout << botCornerLeft;
		else if (i == 3*SIZE + 1)
			cout << botCornerRight;
		else
			cout << horWall;
	}
	cout << endl;
}

/*******************************************************************************************
*	Function Name:			moveTurtle
*	Purpose:				Moves the turtle by calling the move function from the turtle
*							class as well as calls the draw function if the turtle's pen is
*							down in order to draw on the board
*	Input Parameters:		numSpaces - the number of spaces to be moved
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::moveTurtle(int numSpaces)
{
	//input validation
	while (cin.fail()||cin.peek() != '\n')
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Enter the number of spaces to move:";
		cin >> numSpaces;
	}

	//the position before the move is updated to be the previous position
	//int previousX = turtle->getCurrentX();
	//int previousY = turtle->getCurrentY();
	
	turtle->move(numSpaces);
	checkCollision();		//makes sure the turtle doesn't go through the wall
	
	//if the turtle's pen is down, draw
	if(turtle->penDown())
		draw();
	
}

/*******************************************************************************************
*	Function Name:			jumpTurtle
*	Purpose:				Jumps the turtle to a new position chosen by the user to any
*							space on the board.
*	Input Parameters:		newX - the new X position of the turtle
*							newY - the new Y position of the turtle
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::jumpTurtle(int newX, int newY)
{
	//input validation
	while (cin.fail()||cin.peek() != '\n')
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Enter the coordinates of where you would like to jump to:";
		cin >> newX >> newY;
	}

	turtle->jump(newX, newY);
	checkCollision();
	if (turtle->penDown())
		floor[newX][newY] = drawChar;
}

/*******************************************************************************************
*	Function Name:			turnTurtle
*	Purpose:				Tells the turtle to turn the direction chosen by the user
*	Input Parameters:		dir - the direction to turn in, n, s, w, or e
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::turnTurtle(char dir)
{
	//input validation
	while (cin.fail()||cin.peek() != '\n'||dir !='n' && dir != 's' && dir != 'e' && dir != 'w')
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid direction ( n, s, e, or w): ";
		cin >> dir;
	}
	turtle->turn(dir);
}

/*******************************************************************************************
*	Function Name:			resetBoard
*	Purpose:				Returns the board to its original state, including restoring
*							all drawn characters to default, all of the turtle states to
*							default, and the turtle's position to default
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::resetBoard()
{
	//reset turtle position
	turtle->setCurrentX(0);
	turtle->setCurrentY(0);

	//reset turtle direction
	turtle->turn('e');

	//reset turtle pen
	if (turtle->penDown())
		turtle->changePenPosition();

	//initialize board with default values
	initBoard(floor);
}

/*******************************************************************************************
*	Function Name:			draw
*	Purpose:				Replaces any ground tiles in between the turtle's previous
*							position and the turtle's current position with the chosen
*							brush character
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::draw()
{
	//handles horizontal movement
	if (turtle->getCurrentX() - turtle->getPreviousX() >= 0)
	{
		for (int j = turtle->getPreviousX(); j < turtle->getCurrentX(); j++)
			floor[turtle->getPreviousY()][j] = drawChar;
	}
	else
	{
		for (int j = turtle->getPreviousX(); j > turtle->getCurrentX(); j--)
			floor[turtle->getPreviousY()][j] = drawChar;
	}

	//handles verticle movement
	if (turtle->getCurrentY() - turtle->getPreviousY() >= 0)
	{
		for (int i = turtle->getPreviousY(); i < turtle->getCurrentY(); i++)
			floor[i][turtle->getPreviousX()] = drawChar;
	}
	else
	{
		for (int i = turtle->getPreviousY(); i > turtle->getCurrentY(); i--)
			floor[i][turtle->getPreviousX()] = drawChar;
	}
	
}

/*******************************************************************************************
*	Function Name:			togglePen
*	Purpose:				Changes the turtle's pen position from up to down or down to up
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::togglePen()
{
	turtle->changePenPosition();
	floor[turtle->getCurrentY()][turtle->getCurrentX()] = drawChar;		//draws on the current tile
}

/*******************************************************************************************
*	Function Name:			checkCollision
*	Purpose:				Checks whether the turtle's movement makes it run into the wall;
*							if so, the turtle continues until it runs out of room
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::checkCollision()
{
	//horizontal collision
	if (turtle->getCurrentX() > SIZE - 1)
		turtle->setCurrentX(SIZE - 1);
	if (turtle->getCurrentX() < 0)
		turtle->setCurrentX(0);

	//verticle collision
	if (turtle->getCurrentY() > SIZE - 1)
		turtle->setCurrentY(SIZE - 1);
	if (turtle->getCurrentY() < 0)
		turtle->setCurrentY(0);
}

/*******************************************************************************************
*	Function Name:			changeBrush
*	Purpose:				Changes the draw character to be the character chosen by the user
*	Input Parameters:		selection - the number of the brush character to be selected
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::changeBrush(int selection)
{
	//input validation
	while (cin.fail()||cin.peek() != '\n'||turtle->changeBrush(selection) == '1')
	{
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Enter a valid brush option (1, 2, 3, or 4): ";
		cin >> selection;
	}
	drawChar = turtle->changeBrush(selection);
	
}

/*******************************************************************************************
*	Function Name:			printTurtleInfo
*	Purpose:				Prints all of the current information about the turtle, including
*							the current x,y position, the direction, and whether the pen is
*							up or down
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void Board::printTurtleInfo()
{
	cout << "The turtle is at position (" << turtle->getCurrentX() << ", " << turtle->getCurrentY() << ")" << endl;
	cout << "The turtle is facing ";
	switch (turtle->getDirection())
	{
	case 's':
		cout << "south" << endl;
		break;
	case 'n':
		cout << "north" << endl;
		break;
	case 'e':
		cout << "east" << endl;
		break;
	case 'w':
		cout << "west" << endl;
		break;
	}
	
	cout << "The turtle's pen is ";
	if (turtle->penDown())
		cout << "down." << endl;
	else
		cout << "up." << endl;


}
