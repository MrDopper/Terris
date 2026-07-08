#pragma once
#include <vector>
#include <map>
#include "position.hpp"
#include "colors.hpp"

class Block
{
public:
    Block();
    void Draw();
    void move(int row, int col);
    std::vector<Position> GetCellPosition();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffSet;
    int columnOffSet;
};
