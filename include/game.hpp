#pragma once
#include "grid.hpp"
#include "blocks.hpp"

class Game{
    public:
        Game();
        Block getRandomBlocks();
        std::vector<Block> getAllBlocks();
        void Draw();
        void handleInput();
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        Grid grid;

    private:
        bool isOutSide();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

};
