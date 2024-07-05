#include <SFML/Graphics.hpp>
#include "pieces.cpp"


struct Board {

    //Constant variables
    int const boardWidth = 10;
    int const boardHeight = 20;
    int const blockSize = 20;
    int const blocksInPiece = 5;
    enum {EMPTY=0, FULL=1, ROTATION=2};


    Piece* pieces = nullptr;
    int boardXPosition = 0;
    int boardYPosition = 0;
    std::vector<std::vector<int>> board = std::vector<std::vector<int>>(boardHeight, std::vector<int>(boardWidth));

    Board(Piece *pieces, sf::RenderWindow *window) : pieces(pieces) {
        boardXPosition = window->getSize().x / 2 - boardWidth * blockSize / 2;
        boardYPosition = window->getSize().y / 2 - boardHeight * blockSize / 2;
    }

    auto storePiece(int x, int y, int piece, int rotation)-> void {
        for(int iPiece = x, i = 0; iPiece < i + blocksInPiece; iPiece++, i++) {
            for(int jPiece = y, j = 0; jPiece < j + blocksInPiece; jPiece++, j++) {
                if(pieces->getBlockType(piece, rotation, i, j) != EMPTY) {
                    board[iPiece][jPiece] = FULL;
                }
            }
        }
    }

    auto isGameOver() -> bool {
        for(int i = 0; i < boardWidth; i++) {
            if(board[0][i] == FULL) {
                return true;
            }
        }
        return false;
    }

    auto removeRow(int rowNumber) -> void {
        for(int i = rowNumber; i > 0; i--) {
            for(int j = 0; j < boardWidth; j++) {
                board[i][j] = board[i - 1][j];
            }
        }
    }


};