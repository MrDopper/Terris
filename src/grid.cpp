#include "grid.hpp"
#include "colors.hpp"
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

bool Grid::outOfBoundary(int row, int cols)
{
    if (row >= 0 && row < numRows && cols >= 0 && cols < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int cols)
{
    if (grid[row][cols] == 0)
    {
        return true;
    }
    return false;
}

int Grid::clearFullRow()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (isRowFull(row))
        {
            clearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            moveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::isRowFull(int row)
{
    for (int cols = 0; cols < numCols; cols++)
    {
        if (grid[row][cols] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for (int cols = 0; cols < numCols; cols++)
    {
        grid[row][cols] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    for (int cols = 0; cols < numCols; cols++)
    {
        grid[row + numRows][cols] = grid[row][cols];
        grid[row][cols] = 0;
    }
}
