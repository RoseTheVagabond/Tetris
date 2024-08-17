#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    tetrominos = getAllBlocks();
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
    return {IMino(), JMino(), LMino(), OMino(), SMino(), TMino(), ZMino()};
}