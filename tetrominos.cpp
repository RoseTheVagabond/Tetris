#include "block.h"
#include "position.h"

struct LMino : Block {
    LMino() {
        id = 1;
        cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,0), Position(1,0), Position(2,0), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
        cells[3] = {Position(0,1), Position(0,2), Position(1,2), Position(2,2)};
        move(0, 3);
    }
};

struct JMino : Block {
    JMino() {
        id = 2;
        cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
        move(0, 3);
    }
};

struct IMino : Block {
    IMino() {
        id = 3;
        cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
        cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
        cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
        cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
        move(0, 3);
    }
};

struct OMino : Block {
    OMino() {
        id = 4;
        cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
        move(0, 3);
    }
};

struct SMino : Block {
    SMino() {
        id = 5;
        cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
        cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
        cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
        move(0, 3);
    }
};

struct TMino : Block {
    TMino() {
        id = 6;
        cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
        move(0, 3);
    }
};

struct ZMino : Block {
    ZMino() {
        id = 7;
        cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
        cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
        cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
        move(0, 3);
    }
};