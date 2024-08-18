#include "block.h"

Block::Block() {
    cellSize = 30;
    rotation = 0;
    colors = getCellColours();
    rowOffset = 0;
    columnOffset = 0;
}

auto Block::draw(int offsetX, int offsetY) -> void {
    std::vector<Position> tiles = getCellPositions();
    for(Position item : tiles) {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 2, cellSize - 2, colors[3]);
    }
}

auto Block::move(int rows, int columns) -> void{
    rowOffset += rows;
    columnOffset += columns;
}

auto Block::getCellPositions() -> std::vector<Position>{
    std::vector<Position> tiles = cells[rotation];
    std::vector<Position> movedTiles;

    for (Position item : tiles) {
        Position newPosition = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPosition);
    }
    return movedTiles;
}

auto Block::rotate() -> void {
    rotation++;
    if(rotation == cells.size()) {
        rotation = 0;
    }
}

auto Block::undoRotation() -> void {
    rotation--;
    if(rotation < 0) {
        rotation = cells.size() - 1;
    }
}

