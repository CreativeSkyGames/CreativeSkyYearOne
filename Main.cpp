#include "GameManager.h"
//Used to run the game
int main()
{
	cGameManager c(40, 20);
	c.Run();
	cout << "Press a key to continue." << endl;
	system("pause");
	return 0;
}