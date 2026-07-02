#include "grid.hpp"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSizes = 30;
    Initialize();
    colors = getCellColors();
}
void Grid::Initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            grid[row][col] = 0;
        }
    }
}
void Grid::print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

std::vector<Color> Grid::getCellColors()
{
    Color darkGrey = {26, 31, 40, 255};
    Color lightPink = {238, 208, 232, 255};
    Color yellow = {255, 255, 74, 255};
    Color orange = {255, 136, 15, 255};
    Color skyBlue = {168, 202, 255, 255};
    Color navyBlue = {50, 58, 255, 255};
    Color brightLime = {161, 224, 141, 255};

    return {darkGrey, lightPink, yellow, orange, skyBlue, navyBlue, brightLime};
}

void Grid::Draw()
{
    for (int rows = 0; rows < numRows; rows++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            int cellValue = grid[rows][cols];
            DrawRectangle(cols * cellSizes + 1, rows * cellSizes + 1, cellSizes - 1, cellSizes - 1, colors[cellValue]);
        }
    }
}