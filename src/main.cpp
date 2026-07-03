#include <iostream>
#include <raylib.h>
#include "grid.hpp"
using namespace std;

int main()
{
	const int width = 300;
	const int height = 600;
	InitWindow(width, height, "Terris");
	SetTargetFPS(60);
	Grid grid = Grid();
	grid.grid[0][0] = 1;
	grid.grid[3][10] = 4;
	grid.grid[4][6] = 7;
	grid.grid[7][2] = 2;
	grid.print();
	cout << "The game is successfully compile" << endl;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(SKYBLUE);
		grid.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
