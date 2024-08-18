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
    void draw(int offsetX, int offsetY);
    void move(int rows, int columns);
    std::vector<Position> getCellPositions();
    void rotate();
    void undoRotation();
private:
    int cellSize;
    int rotation;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};