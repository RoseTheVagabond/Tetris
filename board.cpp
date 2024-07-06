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

    auto storePiece(int y, int x, int piece, int rotation)-> void {
        for(int iBoard = y, i = 0; iBoard < i + blocksInPiece; iBoard++, i++) {
            for(int jBoard = x, j = 0; jBoard < j + blocksInPiece; jBoard++, j++) {
                if(pieces->getBlockType(piece, rotation, i, j) != EMPTY) {
                    board[iBoard][jBoard] = FULL;
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

    auto isEmptyBlock(int y, int x) -> bool {
        return board[y][x] == EMPTY;
    }

    auto isMovementPossible(int y, int x, int piece, int rotation) -> bool {
        for(int iBoard = y, i = 0; iBoard < i + blocksInPiece; iBoard++, i++) {
            for(int jBoard = x, j = 0; jBoard < j + blocksInPiece; jBoard++, j++) {
                if(pieces->getBlockType(piece, rotation, i, j) != EMPTY) {
                    if(iBoard < 0 || iBoard >= boardHeight || jBoard < 0 || jBoard >= boardWidth) {
                        return false;
                    }
                    if(board[iBoard][jBoard] == FULL || board[iBoard][jBoard] == ROTATION) {
                        return false;
                    }
                    if(!isEmptyBlock(iBoard, jBoard)) {
                        return false;
                    }
                }

            }
        }
        return true;
    }

    auto getPiecePositionX(int piecePositionX) -> int {
        return boardXPosition + piecePositionX * blockSize;
    }

    auto getPiecePositionY(int piecePositionY) -> int {
        return boardYPosition + piecePositionY * blockSize;
    }
};