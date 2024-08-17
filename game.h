#pragma once
#include "grid.h"
#include "tetrominos.cpp"

class Game {
public:
    Game();
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
private:
    std::vector<Block> tetrominos;
};