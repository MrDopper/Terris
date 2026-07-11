#pragma once
#include "grid.hpp"
#include "blocks.hpp"

class Game
{
public:
    Game();
    Block getRandomBlocks();
    std::vector<Block> getAllBlocks();
    void Draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    bool gameOver;
    Grid grid;
    int score;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool isOutSide();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    void Reset();
    void updateScore(int lineCleared, int moveDownBlock);
};
