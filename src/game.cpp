#include "game.hpp"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlocks();
    nextBlock = getRandomBlocks();
    gameOver = false;
    score = 0;
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
    if (gameOver == true && keyPress != 0)
    {
        gameOver = false;
        Reset();
    }
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
        updateScore(0, 1);
        break;

    case KEY_UP:
        rotateBlock();
        break;
    }
}

void Game::moveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.move(0, -1);
        if (isOutSide() || blockFits() == false)
        {
            currentBlock.move(0, 1);
        }
    }
}

void Game::moveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.move(0, 1);
        if (isOutSide() || blockFits() == false)
        {
            currentBlock.move(0, -1);
        }
    }
}

void Game::moveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.move(1, 0);
        if (isOutSide() || blockFits() == false)
        {
            currentBlock.move(-1, 0);
            lockBlock();
        }
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

void Game::rotateBlock()
{
    if (!gameOver)
    {
        currentBlock.blockRotation();
        if (isOutSide() || blockFits() == false)
        {
            currentBlock.undoRotation();
        }
    }
}

void Game::lockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position items : tiles)
    {
        grid.grid[items.rows][items.cols] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (blockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = getRandomBlocks();
    int rowCleared = grid.clearFullRow();
    updateScore(rowCleared, 0);
}

bool Game::blockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item : tiles)
    {
        if (grid.isCellEmpty(item.rows, item.cols) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlocks();
    nextBlock = getRandomBlocks();
    score = 0;
}

void Game::updateScore(int lineCleared, int moveDownBlock)
{
    switch (lineCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 1000;
        break;
    case 4:
        score += 2000;
        break;
    default:
        break;
    }
    score += moveDownBlock;
}
