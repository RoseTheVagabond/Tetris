#include "grid.h"
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

auto Grid::getCellColours() -> std::vector<Color> {
    Color darkBlue = {0, 29, 62, 255};
    Color blue = {0, 53, 102, 255};
    Color orange = {255, 195, 0, 255};
    Color yellow = {255, 214, 10, 255};
    Color almostBlack = {0, 8, 20, 255};

    return {darkBlue, blue, orange, yellow, almostBlack};
}

auto Grid::draw() -> void {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, colors[grid[i][j]]);
        }
    }
}