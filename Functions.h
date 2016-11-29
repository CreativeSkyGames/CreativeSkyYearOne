//This header includes the functions that will be called upon in the gamemanager class
//It also includes classes that will be used in the gamemanager header file
#include <iostream>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



void Rules()
{
	cout << "To play the game you must hit the ball past the enemy paddle." << endl << "You control your paddle with 'w' nad 's'" << endl;
	system("Pause");

}

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
//Used to change the direction of the ball

class cBall
//The ball class, controls the ball for pong
{
private:
	int x, y;
	int originalX, originalY;
//Stores the original 'X' and 'Y' positions
	eDir direction;
//Calls the function into the class

public:
	cBall(int posX, int posY)
	{
		originalX = posX;
		originalY - posY;
		x = posX, y = posY;
		direction = STOP;
	}
	void Reset()
	//A function resets the ball
	{
		x = originalX, y = originalY;
		direction = STOP;
	}

	void changeDirection(eDir d)
	//Function used to creat a change of direction
	{
		direction = d;
	}

	void randomDirection()
	//Function to randomly change the direction
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	void Move()
	//Function to move the ball
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default:
			break;
		};
	}
	friend ostream & operator<<(ostream & o, cBall c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};
class cPaddle
//The paddle class for the player controled paddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPaddle()
//Setting the 'X' and 'Y' to zero
	{
		x = y = 0;
	}
	cPaddle(int posX, int posY) : cPaddle()
//Used to create functions to be used later
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
};

class cAI
//Class for creating the AI paddle, creates most of the same functions as the Paddle class
{
private:
	int x, y;
	int originalX, originalY;
	
public:
	
	
	cAI()
	{
		x = y = 0;
	}
	cAI(int posX, int posY) : cAI()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	
	void move() 
	//Function to move the AI paddle around without keyboard hits
	{
		
		srand(time(NULL));

		int random = (rand() % 2 + 1);

		switch (random)
		{
		case 1: 
			if (y >= 1)
			{
				y--;
				break;
			}
			
			break;

		case 2:
			if (y <= 10)
			{
				y++;
				break;
			}
			
			break;
		
		}
		
	}
};



