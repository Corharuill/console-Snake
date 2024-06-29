#include <iostream>
#include <conio.h>
#include <Windows.h>
struct Position {
	int x=0, y=0;
};
	
struct Variables
{
	bool      game_over;
	const int WIDTH = 20;
	const int HEIGHT = 20;
	int score = 0;
	bool hungary = false;
	Position pos_snake;
	Position pos_food;

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
	for (size_t y = 0; y <= peremen.HEIGHT ; y++)
	{

		for (size_t x = 0; x <= peremen.WIDTH; x++)
		{
			if (y == 0)
				std::cout << "1";
			else if (y == peremen.WIDTH)
				std::cout << "2";
			else if (x == 0 && y != peremen.WIDTH)
				std::cout << "3";
			else if (x == peremen.HEIGHT && y != peremen.WIDTH)
				std::cout << "4";
			else if (y != 0 && y != peremen.WIDTH)
				std::cout << " ";
			
			if (x == rand() % 5 && y == rand() % 5 && peremen.hungary == true) {
				gotoxy(x, y);
				std::cout << "*";
			}

			if (x == peremen.pos_snake.x && y == peremen.pos_snake.y)
			{
				gotoxy(x, y);
				std::cout << "@";
			}

			if (peremen.pos_food.x == peremen.pos_snake.x && peremen.pos_food.y == peremen.pos_snake.y) {
				peremen.score++;
				peremen.hungary = true;
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
	Position pos;
	
	

	while (true)
	{
		Draw();
		//system("cls");
		gotoxy(22, 0);
		
		std::cout << "SCORE:" << peremen.score;
		gotoxy(0, 0);
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				if (peremen.dir  != Variables::DOWN)
					peremen.dir = Variables::UP;
				break;
			case 'a':
				if (peremen.dir != Variables::RIGHT)
					peremen.dir = Variables::LEFT;
				break;
			case 's':
				if (peremen.dir != Variables::UP)
					peremen.dir = Variables::DOWN;
				break;
			case 'd':
				if (peremen.dir != Variables::LEFT)
					peremen.dir = Variables::RIGHT;
				break;
				

			}
			switch (peremen.dir)
			{
			case Variables::LEFT:
				peremen.pos_snake.x--;
				break;
			case Variables::RIGHT:
				peremen.pos_snake.x++;
				break;
			case Variables::UP:
				peremen.pos_snake.y--;
				break;
			case Variables::DOWN:
				peremen.pos_snake.y++;
				break;
			}
		}
		
	}
	
	
	Input();
	Logic();

	return 0;
}
