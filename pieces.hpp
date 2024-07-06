#ifndef _PIECES_
#define _PIECES_
#include <vector>

// Define the pieces array
extern int pieces[7][4][5][5];

struct Piece {
    int getBlockType(int piece, int rotation, int y, int x) {
        return pieces[piece][rotation][y][x];
    }

    std::vector<int> getInitialPosition(int piece, int rotation) {
        return {-2, -2}; // This is a placeholder, modify as needed
    }
};

#endif //_PIECES_