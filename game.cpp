#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    tetrominos = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

Block Game::getRandomBlock() {
    if(tetrominos.empty()) {
        tetrominos = getAllBlocks();
    }
    int randomIndex = rand() % tetrominos.size();
    Block mino = tetrominos[randomIndex];
    tetrominos.erase(tetrominos.begin() + randomIndex);
    return mino;
}

std::vector<Block> Game::getAllBlocks() {
    std::vector<Block> blocks = {IMino(), JMino(), LMino(), OMino(), SMino(), TMino(), ZMino()};

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(blocks.begin(), blocks.end(), rng);
    return blocks;
}

void Game::draw() {
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput() {
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
    }
}

void Game::moveBlockLeft() {
    currentBlock.move(0,-1);
    if(isBlockOutside()) {
        currentBlock.move(0, 1);
    }
}

void Game::moveBlockRight() {
    currentBlock.move(0, 1);
    if(isBlockOutside()) {
        currentBlock.move(0, -1);
    }
}

void Game::moveBlockDown() {
    currentBlock.move(1, 0);
    if(isBlockOutside()) {
        currentBlock.move(-1, 0);
    }
}

bool Game::isBlockOutside() {
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item : tiles) {
        if(grid.isCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}