#include "game.hpp"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlocks();
    nextBlock = getRandomBlocks();
}

Block Game::getRandomBlocks()
{
    if (blocks.empty())
    {
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), LBlock(), OBlock(), TBlock(), JBlock(), ZBlock(), SBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::handleInput()
{
    int keyPress = GetKeyPressed();
    switch (keyPress)
    {
    case KEY_LEFT:
        moveBlockLeft();
        break;

    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        break;
    }
}

void Game::moveBlockLeft()
{
    currentBlock.move(0, -1);
    if (isOutSide())
    {
        currentBlock.move(0, 1);
    }
}

void Game::moveBlockRight()
{
    currentBlock.move(0, 1);
    if (isOutSide())
    {
        currentBlock.move(0, -1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.move(1, 0);
    if (isOutSide())
    {
        currentBlock.move(-1, 0);
    }
}

bool Game::isOutSide()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item : tiles)
    {
        if (grid.outOfBoundary(item.rows, item.cols))
        {
            return true;
        }
    }
    return false;
}
