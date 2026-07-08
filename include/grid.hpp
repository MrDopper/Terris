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
    int grid[20][10];

private:
    int numCols;
    int numRows;
    int cellSizes;
    std::vector<Color> colors;
};
