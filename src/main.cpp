#include <iostream>
#include <raylib.h>
#include "game.hpp"

double lastUpdateTime = 0;
bool eventTrigger(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}
using namespace std;

int main()
{
	const int width = 520;
	const int height = 620;
	InitWindow(width, height, "Terris");
	SetTargetFPS(60);
	Font font = LoadFontEx("assets/font/gameFont.otf", 64, 0, 0);
	Game game = Game();
	while (!WindowShouldClose())
	{
		game.handleInput();
		if (eventTrigger(0.4))
		{
			game.moveBlockDown();
		}
		BeginDrawing();
		ClearBackground(SKYBLUE);
		DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
		DrawTextEx(font, "Next", {370, 170}, 38, 2, WHITE);
		if (game.gameOver)
		{

			DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
		}
		DrawRectangleRounded({335, 55, 170, 60}, 0.3, 6, LIGHTGRAY);
		DrawRectangleRounded({335, 215, 170, 180}, 0.3, 6, LIGHTGRAY);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
