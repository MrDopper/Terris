#pragma once
#include <iostream>
#include <vector>
#include <raylib.h>
using namespace std;
class Grid
{
public:
    Grid();
    void Initialize();
    void print();
    void Draw();
    bool outOfBoundary(int row, int cols);
    bool isCellEmpty(int row, int cols);
    int clearFullRow();
    int grid[20][10];

private:
    int numCols;
    int numRows;
    int cellSizes;
    std::vector<Color> colors;
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
};
