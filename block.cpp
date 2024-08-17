#include "block.h"

Block::Block() {
    cellSize = 30;
    rotation = 0;
    colors = getCellColours();
    rowOffset = 0;
    columnOffset = 0;
}

auto Block::draw() -> void {
    std::vector<Position> tiles = cells[rotation];
    for(Position item : tiles) {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 2, cellSize - 2, colors[3]);
    }
}

void Block::move(int rows, int columns) {

}