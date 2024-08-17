#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    void initGrid();
    int grid[20][10];
    void print();
    void draw();
    std::vector<Color> colors;
    bool isCellOutside(int row, int column);
    bool isCellEmpty(int row, int column);
    int clearFullRows();
private:
    int numRows;
    int numColumns;
    int cellSize;
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
};
