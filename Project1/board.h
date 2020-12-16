#include "turtle.h"
#ifndef BOARD_H
#define BOARD_H
/**************************************************************************************************
*
*   File name :			board.h
*
*	Programmer:  		Jeremy Atkins
*
*   Header file for the Board class, implemented in board.cpp
*
*   Date Written:		in the past
*
*   Date Last Revised:	10/14/18
*
*	Class Name:		Board
*
*	Private data members:
*		SIZE - the size of the board
*		floor - a double pointer used to construct the board
*		groundChar - the character used for the ground
*		turtleChar - the character used for the turtle
*		topCornerLeft, 
*		topCornerRight, 
*		botCornerLeft, 
*		botCornerRight, 
*		horWall,
*		vertWall - characters used to build the border
*		turtle - a pointer to a Turtle object
*
*	Private member functions:
*		checkCollision - checks to make sure the turtle stays in bounds
*		initBoard - initializes the board with the appropriate characters
*
*	Public member functions:
*		Board() - constructor for a Board object
*		~Board() - destructor for a Board object
*		printBoard - prints the board out
*		moveTurtle - moves the turtle linearly according to its direction
*		jumpTurtle - changes the turtle's x and y coordinates
*		turnTurtle - changes the turtle's direction
*		resetBoard - returns the board and turtle to their default state
*		draw - draws on the board according to the turtle's movements
*		togglePen - moves the pen up or down
*		printTurtleInfo - prints out current information about the turtle
****************************************************************************************************/
class Board
{
public:
	Board();
	~Board();
	void printBoard();
	void moveTurtle(int);
	void jumpTurtle(int, int);
	void turnTurtle(char);
	void resetBoard();
	void draw();
	void togglePen();
	void changeBrush(int);
	void printTurtleInfo();
private:
	
	int SIZE;
	char** floor;
	
	char groundChar;
	char turtleChar;
	char drawChar;
	char topCornerLeft;
	char topCornerRight;
	char botCornerLeft;
	char botCornerRight;
	char horWall;
	char vertWall;
	
	Turtle* turtle;

	void checkCollision();
	void initBoard(char**);
};

#endif
