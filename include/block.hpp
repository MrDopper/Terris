#pragma once
#include <vector>
#include <map>
#include "position.hpp"
#include "colors.hpp"

class Block
{
public:
    int id;
    std::map<int, std::vector<Position>> cells;
    Block();
    void Draw();
    void move(int row, int col);
    std::vector<Position> GetCellPosition();
    void blockRotation();
    void undoRotation();

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffSet;
    int columnOffSet;
};
