#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    tetrominos = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

auto Game::getRandomBlock() -> Block{
    if(tetrominos.empty()) {
        tetrominos = getAllBlocks();
    }
    int randomIndex = rand() % tetrominos.size();
    Block mino = tetrominos[randomIndex];
    tetrominos.erase(tetrominos.begin() + randomIndex);
    return mino;
}

auto Game::getAllBlocks() -> std::vector<Block>{
    std::vector<Block> blocks = {IMino(), JMino(), LMino(), OMino(), SMino(), TMino(), ZMino()};

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(blocks.begin(), blocks.end(), rng);
    return blocks;
}

auto Game::draw() -> void{
    grid.draw();
    currentBlock.draw();
}

auto Game::handleInput() -> void {
    int keyPressed = GetKeyPressed();
    switch(keyPressed) {
        case KEY_LEFT:
        case KEY_A:
            moveBlockLeft();
            break;
        case KEY_RIGHT:
        case KEY_D:
            moveBlockRight();
            break;
        case KEY_DOWN:
        case KEY_S:
            moveBlockDown();
            break;
        case KEY_UP:
        case KEY_W:
            rotateBlock();
            break;

    }
}

auto Game::moveBlockLeft() -> void{
    currentBlock.move(0,-1);
    if(isBlockOutside() || !blockFits()) {
        currentBlock.move(0, 1);
    }
}

auto Game::moveBlockRight() -> void {
    currentBlock.move(0, 1);
    if(isBlockOutside() || !blockFits()) {
        currentBlock.move(0, -1);
    }
}

auto Game::moveBlockDown() -> void{
    currentBlock.move(1, 0);
    if(isBlockOutside() || !blockFits()) {
        currentBlock.move(-1, 0);
        lockBlock();
    }
}

auto Game::isBlockOutside() -> bool {
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item : tiles) {
        if(grid.isCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}

auto Game::rotateBlock() -> void {
    currentBlock.rotate();
    if(isBlockOutside()) {
        currentBlock.undoRotation();
    }
};

auto Game::lockBlock() -> void {
    std::vector<Position> tiles = currentBlock.getCellPositions();

    for(Position item : tiles) {
        grid.grid[item.row][item.column] = 2;
    }
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
}

auto Game::blockFits() -> bool {
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item : tiles) {
       if(!grid.isCellEmpty(item.row, item.column)) {
           return false;
       }
    }
    return true;
}


















