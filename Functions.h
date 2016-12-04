//This header includes the functions that will be called Uon in the gamemanager class
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

enum eDir { S = 0, L = 1, UL = 2, DL = 3, R = 4, UR = 5, DR = 6 };
//Used to change the Direc of the ball

class Pellet
//The ball class, controls the ball for pong
{
private:
	int x, y;
	int startX, startY;
//Stores the original 'X' and 'Y' positions
	eDir Direc;
//Calls the function into the class

public:
	Pellet(int posX, int posY)
	{
		startX = posX;
		startY - posY;
		x = posX, y = posY;
		Direc = S;
	}
	void Reset()
	//A function resets the ball
	{
		x = startX, y = startY;
		Direc = S;
	}

	void changeDirec(eDir d)
	//Function used to creat a change of Direc
	{
		Direc = d;
	}

	void randomDirec()
	//Function to randomly change the Direc
	{
		Direc = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirec() { return Direc; }
	void Move()
	//Function to move the ball
	{
		switch (Direc)
		{
		case S:
			break;
		case L:
			x--;
			break;
		case R:
			x++;
			break;
		case UL:
			x--; y--;
			break;
		case DL:
			x--; y++;
			break;
		case UR:
			x++; y--;
			break;
		case DR:
			x++; y++;
			break;
		default:
			break;
		};
	}
	
};
class Human
//The paddle class for the player controled paddle
{
private:
	int x, y;
	int startX, startY;
public:
	Human()
//Setting the 'X' and 'Y' to zero
	{
		x = y = 0;
	}
	Human(int posX, int posY) : Human()
//Used to create functions to be used later
	{
		startX = posX;
		startY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = startX; y = startY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveU() { y--; }
	inline void moveD() { y++; }
};

class cAI
//Class for creating the AI paddle, creates most of the same functions as the Paddle class
{
private:
	int x, y;
	int startX, startY;
	
public:
	
	
	cAI()
	{
		x = y = 0;
	}
	cAI(int posX, int posY) : cAI()
	{
		startX = posX;
		startY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = startX; y = startY; }
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
