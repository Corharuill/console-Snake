#pragma once
struct Position
{
	int x = 0;
	int y = 0;
};

// Структура Переменные
struct Variables
{
	bool     game_over;
	const    int WIDTH = 20;
	const    int HEIGHT = 20;
	int      score = 0;
	bool     hungary = false;
	Position pos_snake = { 1, 1 };
	Position old_pos_food = { 1, 1 };
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
class Game
{
public:
	

	Variables peremen;

	// Структура Переменные
	Game();
	~Game();
	void Input();
	void Draw();
	void Setup();
	void gotoxy(int x, int y);
	void Logic();
	Position getRandPosition();
private:

};
