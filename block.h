#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colours.h"

class Block {
public:
    Block();
    int id;
    std::map<int, std::vector<Position>> cells;
    void draw();
    void move(int rows, int columns);
private:
    int cellSize;
    int rotation;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};