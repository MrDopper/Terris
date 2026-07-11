#pragma once
#include "grid.hpp"
#include "blocks.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void handleInput();
    void moveBlockDown();
    bool gameOver;
    int score;
    Music music;
    
    private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    void moveBlockLeft();
    void moveBlockRight();
    bool isOutSide();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    void Reset();
    void updateScore(int lineCleared, int moveDownBlock);
    Block getRandomBlocks();
    std::vector<Block> getAllBlocks();
    Sound rotateSound();
    Sound clearSound();
};
