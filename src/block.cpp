#include "block.hpp"
Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
    rowOffSet = 0;
    columnOffSet = 0;
}
void Block ::Draw(int offSetX,int offSetY)
{
    std::vector<Position> tiles = GetCellPosition();
    for (Position item : tiles)
    {
        DrawRectangle(item.cols * cellSize + offSetX, item.rows * cellSize + offSetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int row, int col)
{
    rowOffSet += row;
    columnOffSet += col;
}
std::vector<Position> Block::GetCellPosition()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> moveTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.rows + rowOffSet, item.cols + columnOffSet);
        moveTiles.push_back(newPos);
    }
    return moveTiles;
}

void Block::blockRotation()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::undoRotation()
{
    rotationState --;
    if(rotationState == -1){
        rotationState = cells.size() -1;
    }
}
