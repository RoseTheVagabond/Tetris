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
            DrawRectangle(j * cellSize + 11, i * cellSize + 11, cellSize - 1, cellSize - 1, colors[grid[i][j]]);
        }
    }
}

auto Grid::isCellOutside(int row, int column) -> bool {
    if(row >= 0 && row < numRows && column >= 0 && column < numColumns) {
        return false;
    }
    return true;
}

auto Grid::isCellEmpty(int row, int column) -> bool {
    if(grid[row][column] == 0) {
        return true;
    } else {
        return false;
    }
}

auto Grid::isRowFull(int row) -> bool {
    for(int column = 0; column < numColumns; column++) {
        if(grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

auto Grid::clearRow(int row) -> void {
    for(int column = 0; column < numColumns; column++) {
        grid[row][column] = 0;
    }
}

auto Grid::moveRowDown(int row, int numRows) -> void {
    for(int column = 0; column < numColumns; column++) {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

auto Grid::clearFullRows() -> int {
    int completed = 0;
    for(int row = numRows - 1; row >= 0; row--) {
        if(isRowFull(row)) {
            clearRow(row);
            completed++;
        } else if(completed > 0) {
            moveRowDown(row, completed);
        }
    }
    return completed;
}