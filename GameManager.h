#include "Functions.h"
#include <Windows.h>
//Calling the functions header to use the functions in gamemanager

class cGameManager
//Creating a gamemanager class to manage all of the functions from the other header file
{
private:
	
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall * ball;
	cPaddle * player1;
	cAI * ai;
public:
	void gotoxy(int column, int line)
	{
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//Setting the 'X' and 'Y' to lines and columns
	}

	cGameManager(int w, int h)
	//Setting all of the important features of the game (i.e. button for moving up)
	{
		srand(time(0));
		quit = false;
		up1 = 'w';
		down1 = 's';
		score1 = 0;
		width = w; height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		ai = new cAI(w - 2, h / 2 - 3);
	}

	cGameManager()
	{
		delete ball, player1, ai;
//Used to reset the game after a point is given
	}

	//functions to control the score
	void ScoreUp(cPaddle * player)
	{
		score1++;
	}
	void ScoreDown(cPaddle * player)
	{
		score1--;
	}
void Draw()
//Function to draw the game
{
	gotoxy(0, 0);
	for (int i = 0; i < width + 2; i++)
//Used to reset the board to (0,0) to reduce blinking board state
		cout << "\xB2";
	cout << endl;

	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int ballx = ball->getX();
			int bally = ball->getY();
			int player1x = player1->getX();
			int aix = ai->getX();
			int player1y = player1->getY();
			int aiy = ai->getY();

			if (j == 0)
				cout << "\xB2";
		//used to draw the board

			if (ballx == j && bally == i)
				cout << "o";

		//used to draw the paddles
			else if (player1x == j && player1y == i)
				cout << "\xDB";
			else if (player1x == j && player1y + 1 == i)
				cout << "\xDB";
			else if (player1x == j && player1y + 2 == i)
				cout << "\xDB";
			else if (player1x == j && player1y + 3 == i)
				cout << "\xDB";
			else if (aix == j && aiy == i)
				cout << "\xDB";
			else if (aix == j && aiy + 1 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 2 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 3 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 4 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 5 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 6 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 7 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 8 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 9 == i)
				cout << "\xDB";
			else if (aix == j && aiy + 10 == i)
				cout << "\xDB";
			else
					cout << " ";

			if (j == width - 1)
				cout << "\xB2";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	//used to draw the border
	cout << endl;
}
void Input()
//function for keyboard input
{
	ball->Move();

	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player1y = player1->getY();
	int aix = ai->getX();
	int aiy = ai->getY();
	

	if (_kbhit())
	{
		char current = _getch();
		if (current == up1)
			if (player1y > 0)
				player1->moveUp();
		if (current == down1)
			if (player1y + 4 < height)
				player1->moveDown();
		if (current == up1)
				ai->move();
		if (current == down1)
				ai->move();
		if (ball->getDirection() == STOP)
			ball->randomDirection();

		if (current == 'q')
			quit = true;
	}
	else if (!_kbhit())
	{
		ai->move();
	}

}

void Logic()
//The function for creating the boarder, deciding on the ball direction, and if the player won
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int aix = ai->getX();
	int player1y = player1->getY();
	int aiy = ai->getY();



	for (int i = 0; i < 4; i++)
		if (ballx == player1x + 1)
			if (bally == player1y + i)
				ball->changeDirection((eDir)((rand() % 3) + 4));

	for (int i = 0; i < 12; i++)
		if (ballx == aix - 1)
			if (bally == aiy + i)
				ball->changeDirection((eDir)((rand() % 3) + 1));

	if (bally == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

	if (bally == 0)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

	if (ballx == width - 1)
	{
		ScoreUp(player1);
		cout << "\t\t " << "You win" << endl;
	}
	else if (ballx == 0)
	{
		ScoreDown(player1);
		cout << "\t\t " << "You lose" << endl;
	}
}
void Run()
//function for running the game
{
	Rules();
	while (score1 == 0)
	{
		Draw();
		Input();
		Logic();
	}

}
};
