#include "Functions.h"
#include <Windows.h>
//Calling the functions header to use the functions in gamemanager

class cGameManager
//Creating a gamemanager class to manage all of the functions from the other header file
{
private:
	
	int width, height;
	int points, score2;
	char U, D, U2, D2;
	bool quit;
	Pellet * ball;
	Human * player;
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
	//Setting all of the important features of the game (i.e. button for moving U)
	{
		srand(time(0));
		quit = false;
		U = 'w';
		D = 's';
		points = 0;
		width = w; height = h;
		ball = new Pellet(w / 2, h / 2);
		player = new Human(1, h / 2 - 3);
		ai = new cAI(w - 2, h / 2 - 3);
	}

	cGameManager()
	{
		delete ball, player, ai;
//Used to reset the game after a point is given
	}

	//functions to control the score
	//ScoreU means score up
	void ScoreU(Human * player)
	{
		points++;
	}
	//ScoreD means score down
	void ScoreD(Human * player)
	{
		points--;
	}
void Board()
//Function to Board the game
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
			int playerx = player->getX();
			int aix = ai->getX();
			int playery = player->getY();
			int aiy = ai->getY();

			if (j == 0)
				cout << "\xB2";
		//used to Board the board

			if (ballx == j && bally == i)
				cout << "o";

		//used to Board the paddles
			else if (playerx == j && playery == i)
				cout << "\xDB";
			else if (playerx == j && playery + 1 == i)
				cout << "\xDB";
			else if (playerx == j && playery + 2 == i)
				cout << "\xDB";
			else if (playerx == j && playery + 3 == i)
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
	//used to Board the border
	cout << endl;
}
void Log()
//function for keyboard Log
{
	ball->Move();

	int ballx = ball->getX();
	int bally = ball->getY();
	int playerx = player->getX();
	int playery = player->getY();
	int aix = ai->getX();
	int aiy = ai->getY();
	

	if (_kbhit())
	{
		char current = _getch();
		if (current == U)
			if (playery > 0)
				player->moveU();
		if (current == D)
			if (playery + 4 < height)
				player->moveD();
		if (current == U)
				ai->move();
		if (current == D)
				ai->move();
		if (ball->getDirec() == S)
			ball->randomDirec();

		if (current == 'q')
			quit = true;
	}
	else if (!_kbhit())
	{
		ai->move();
	}

}

void Rational()
//The function for creating the boarder, deciding on the ball Direc, and if the player won
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int playerx = player->getX();
	int aix = ai->getX();
	int playery = player->getY();
	int aiy = ai->getY();



	for (int i = 0; i < 4; i++)
		if (ballx == playerx + 1)
			if (bally == playery + i)
				ball->changeDirec((eDir)((rand() % 3) + 4));

	for (int i = 0; i < 12; i++)
		if (ballx == aix - 1)
			if (bally == aiy + i)
				ball->changeDirec((eDir)((rand() % 3) + 1));

	if (bally == height - 1)
		ball->changeDirec(ball->getDirec() == DR ? UR : UL);

	if (bally == 0)
		ball->changeDirec(ball->getDirec() == UR ? DR : DL);

	if (ballx == width - 1)
	{
		ScoreU(player);
		cout << "\t\t " << "You win" << endl;
	}
	else if (ballx == 0)
	{
		ScoreD(player);
		cout << "\t\t " << "You lose" << endl;
	}
}
void Run()
//function for running the game
{
	Rules();
	while (points == 0)
	{
		Board();
		Log();
		Rational();
	}

}
};
