#include <iostream>
#include <conio.h>
#include <Windows.h>

struct Variables
{
	bool      game_over;
	const int WIDTH = 20;
	const int HEIGHT = 20;

	enum  Direction
	{
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	Direction dir;
};
Variables peremen;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw()
{
	for (size_t x = 0; x <= peremen.HEIGHT ; x++)
	{

		for (size_t y = 0; y <= peremen.WIDTH; y++)
		{
			if (y == 0)
				std::cout << "#";
			else if (y == peremen.WIDTH)
				std::cout << "#";
			else if (x == 0 && y != peremen.WIDTH)
				std::cout << "#";
			else if (x == peremen.HEIGHT && y != peremen.WIDTH)
				std::cout << "#";
			else if (y != 0 && y != peremen.WIDTH)
				std::cout << "-";

			if (x == 10 && y == 10)
			{
				gotoxy(10, 10);
				std::cout << "@";
			}
		}

		std::cout << std::endl;
	}
}

void Input()
{

}

void Logic()
{

}

int main()
{
	Draw();
	Input();
	Logic();

	return 0;
}