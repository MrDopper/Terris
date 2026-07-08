#include "block.hpp"
Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
}
void Block :: Draw(){
    std::vector<Position> tiles = cells[rotationState];
    for(Position item : tiles)
    {
        DrawRectangle(item.cols * cellSize + 1, item.rows * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}