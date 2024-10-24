#include "stdafx.hpp"
#include "Game.hpp"


// Главный метод
int main()
{
	Game game;
	game.Setup();
	while (true)
	{
		game.Draw();
		game.gotoxy(22, 0);
		
		std::cout << "SCORE:" << game.peremen.score;
		game.gotoxy(0, 0);
		if (_kbhit())
		{
			game.Input();
			game.Logic();
		}
	}
	return 0;
}
