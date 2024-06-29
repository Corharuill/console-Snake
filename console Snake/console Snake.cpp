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

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw()
{
	for (size_t x = 0; x <= 20; x++)
	{

		for (size_t y = 0; y <= 20; y++)
		{
			if (y == 0)
				std::cout << "#";
			else if (y == 20)
				std::cout << "#";
			else if (x == 0 && y != 20)
				std::cout << "*";
			else if (x == 20 && y != 20)
				std::cout << "*";
			else if (y != 0 && y != 20)
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