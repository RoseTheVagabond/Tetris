#pragma once
#include "grid.h"
#include "tetrominos.cpp"

class Game {
public:
    bool gameOver;
    int score;
    Music music;
    Sound rotateSound;
    Sound clearSound;
    Game();
    ~Game();
    void draw();
    void handleInput();
    void moveBlockDown();
private:
    std::vector<Block> tetrominos;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void moveBlockLeft();
    void moveBlockRight();
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    void reset();
    void updateScore(int linesCleared, int moveDownPoints);
};