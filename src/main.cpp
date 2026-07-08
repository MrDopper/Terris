#include <iostream>
#include <raylib.h>
#include "grid.hpp"
#include "blocks.cpp"
using namespace std;

int main()
{
	const int width = 300;
	const int height = 600;
	InitWindow(width, height, "Terris");
	SetTargetFPS(60);
	Grid grid = Grid();
	grid.print();

	LBlock block = LBlock();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(SKYBLUE);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
