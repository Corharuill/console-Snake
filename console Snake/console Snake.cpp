#include <iostream>
#include <conio.h>
#include <Windows.h>

 //Структура Позиция.
 //Используется для обозначения координат в пространстве для разных объектов.
 //Position pos;
 //pos.x = 1
struct Position 
{
	int x = 0;
	int y = 0;
};

// Структура Переменные
struct Variables
{
	bool     game_over;
	const    int WIDTH  = 20;
	const    int HEIGHT = 20;
	int      score      = 0;
	bool     hungary    = false;
	Position pos_snake;
	Position old_pos_food;
	Position new_pos_food;

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

// Вспомогаетльный метод для перемещения корретки курсора в консоли в заданные координаты
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Position getRandPosition()
{
	srand(time(0));

	if (peremen.old_pos_food.x != peremen.HEIGHT && peremen.old_pos_food.y != peremen.WIDTH
		&& peremen.old_pos_food.x != 0 && peremen.old_pos_food.y != 0)
	{
		peremen.old_pos_food.x = rand() % peremen.WIDTH;
		peremen.old_pos_food.y = rand() % peremen.HEIGHT;
	}
	return peremen.old_pos_food;
   
}

// Стартовые данные
void Setup()
{
	// Стартовыая позиция еды

	peremen.old_pos_food = getRandPosition();
	// Стартовая позиция персонажа

	peremen.pos_snake.x = rand() % peremen.WIDTH;
	peremen.pos_snake.y = rand() % peremen.HEIGHT;

}

// Метод отрисовки
void Draw()
{
	for (size_t y = 0; y <= peremen.HEIGHT ; y++)
	{

		for (size_t x = 0; x <= peremen.WIDTH; x++)
		{
			// отрисовка краев карты
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
			
			// отрисовка еды
			if (x == peremen.old_pos_food.x && y == peremen.old_pos_food.y) 
			{
				gotoxy(x, y);
				std::cout << "F";
			}

			if (x == peremen.pos_snake.x && y == peremen.pos_snake.y)
			{
				gotoxy(x, y);
				std::cout << "@";
			}

			if (peremen.old_pos_food.x == peremen.pos_snake.x && 
				peremen.old_pos_food.y == peremen.pos_snake.y) 
			{
				peremen.score++;
				peremen.hungary = true;
			}
		}
		std::cout << std::endl;
	}
}

// Метод ввода-вывода (нажати клавиш)
void Input()
{
	switch (_getch())
	{
	case 'w':
			peremen.dir = Variables::UP;
		break;
	case 'a':
			peremen.dir = Variables::LEFT;
		break;
	case 's':
			peremen.dir = Variables::DOWN;
		break;
	case 'd':
			peremen.dir = Variables::RIGHT;
		break;
	}

}

// Метод отвечающий за игровую логику
void Logic()
{
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


// Главный метод
int main()
{
	

	Setup();
	while (true)
	{
		Draw();
		gotoxy(22, 0);
		
		std::cout << "SCORE:" << peremen.score;
		gotoxy(0, 0);
		if (_kbhit())
		{
			Input();
			Logic();
		}
	}
	
	return 0;
}
