#include "grid.h"
#include "colours.h"
#include <iostream>

Grid::Grid() : numRows(20), numColumns(10), cellSize(30) {
    initGrid();
    colors = getCellColours();
};

auto Grid::initGrid() -> void {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            grid[i][j] = 0;
        }
    }
}

auto Grid::print() -> void {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

auto Grid::draw() -> void {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, colors[grid[i][j]]);
        }
    }
}

auto Grid::isCellOutside(int row, int column) -> bool {
    if(row >= 0 && row < numRows && column >= 0 && column < numColumns) {
        return false;
    }
    return true;
}