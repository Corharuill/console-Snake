//��������� �������.
//������������ ��� ����������� ��������� � ������������ ��� ������ ��������.
//Position pos;
//pos.x = 1
#include "stdafx.hpp"
#include "Game.hpp"




// ��������������� ����� ��� ����������� �������� ������� � ������� � �������� ����������
void Game::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Game::Play()
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
}

// ���������� �������� �������� ���������� ��� ���
// TO DO ��������� ����� ��������� ���������� ��� ������ �������
Position Game::getRandPosition()
{
	srand(time(0));
	peremen.old_pos_food.x = (rand() % (peremen.WIDTH - 1)) + 1;
	peremen.old_pos_food.y = (rand() % (peremen.HEIGHT - 1)) + 1;
	return peremen.old_pos_food;
}


// ��������� ������
void Game::Setup()
{
	// ���������� ������� ���
	peremen.old_pos_food = getRandPosition();

	// ��������� ������� ���������
	peremen.pos_snake.x = rand() % peremen.WIDTH;
	peremen.pos_snake.y = rand() % peremen.HEIGHT;
}

// ����� ���������
void Game::Draw()
{
	for (size_t y = 0; y <= peremen.HEIGHT; y++)
	{
		for (size_t x = 0; x <= peremen.WIDTH; x++)
		{

			// ��������� ����� �����
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

			// ��������� ���
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

// ����� �����-������ (������ ������)
void Game::Input()
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

// ����� ���������� �� ������� ������
void Game::Logic()
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
