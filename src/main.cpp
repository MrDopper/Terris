#include <iostream>
#include <raylib.h>
#include "game.hpp"
using namespace std;

int main()
{
	const int width = 300;
	const int height = 600;
	InitWindow(width, height, "Terris");
	SetTargetFPS(60);
	Grid grid = Grid();
	grid.print();

	Game game = Game();
	while (!WindowShouldClose())
	{
		game.handleInput();
		BeginDrawing();
		ClearBackground(SKYBLUE);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
