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
    int grid[20][10];

private:
    std::vector<Color> getCellColors();
    int numCols;
    int numRows;
    int cellSizes;
    std::vector<Color> colors;
};
