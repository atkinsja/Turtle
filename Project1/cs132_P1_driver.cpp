/**************************************************************************************************
*
*   File name :			cs132_P1_driver.cpp
*
*	Programmer:  		Jeremy Atkins
*
*   Driver file. Sets up and prints the menu and all of the user interactions with the turtle
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
****************************************************************************************************/

#include "turtle.h"
#include "direction.h"
#include "position.h"
#include "pen.h"
#include "board.h"
#include <iostream>

using namespace std;
void printMenu();		//fucntion for printing the menu
int main()
{
	Board* floor = new Board;		//creates new board class
	floor->printBoard();

	//user input variables
	int input, numSpaces, posX, posY, brushSelection;
	char dir;

	floor->printTurtleInfo();

	//start do-while
	do
	{
		printMenu();
		cin >> input;

		//input validation
		while (cin.fail() || cin.peek() != '\n' || input > 9 || input < 1)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Incorrect input.\nPlease enter a value between 1 and 9:\n";
			printMenu();
			cin >> input;
		}
		
		//switch for the main menu
		switch (input)
		{
		case 1:		//pen toggle
			floor->togglePen();
			floor->printTurtleInfo();
			break;
		case 2:		//direction change
			cout << "Which direction would you like to move (n, s, w, e)?: ";
			cin >> dir;
			tolower(dir);
			floor->turnTurtle(dir);
			floor->printTurtleInfo();
			break;
		case 3:		//move
			cout << "How many spaces would you like to move?: ";
			cin >> numSpaces;
			floor->moveTurtle(numSpaces);
			floor->printTurtleInfo();
			break;
		case 4:		//print board
			floor->printBoard();
			floor->printTurtleInfo();
			break;
		case 5:		//brush change
			cout << "1. O" << endl;
			cout << "2. *" << endl;
			cout << "3. &" << endl;
			cout << "4. %" << endl;
			cout << "Select which brush to draw with: ";
			cin >> brushSelection;
			floor->changeBrush(brushSelection);
			floor->printTurtleInfo();
			break;
		case 6:		//reset board
			floor->resetBoard();
			floor->printTurtleInfo();
			break;
		case 7:		//jump
			cout << "Enter the x and y coordinates to jump to: " << endl;
			cin >> posX >> posY;
			floor->jumpTurtle(posX, posY);
			floor->printTurtleInfo();
			break;
		case 8:		//print the menu
			printMenu();
			floor->printTurtleInfo();
			break;
		case 9:		//exit
			break;
		default:
			cout << "Incorrect value entered. Please enter an integer between 1 and 9" << endl;
		}
	} while (input != 9);		//end do-while

	delete floor;				//delete the board
	return 0;
}

/*******************************************************************************************
*	Function Name:			printMenu
*	Purpose:				prints the menu for display to the user
*	Input Parameters:		none
*	Output Parameters:		none
*	Return value:			none
********************************************************************************************/
void printMenu()
{
	cout << "1		change pen position" << endl;
	cout << "2		turn" << endl;
	cout << "3		move forward" << endl;
	cout << "4		print" << endl;
	cout << "5		change brush" << endl;
	cout << "6		erase/start over" << endl;
	cout << "7		jump" << endl;
	cout << "8		see menu again" << endl;
	cout << "9		end program" << endl;
	cout << "Enter your option: ";
}

