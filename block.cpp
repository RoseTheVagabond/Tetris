#include "block.h"

Block::Block() {
    cellSize = 30;
    rotation = 0;
    colors = getCellColours();
}

auto Block::draw() -> void {
    std::vector<Position> tiles = cells[rotation];
    for(Position item : tiles) {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 2, cellSize - 2, colors[3]);
    }
}