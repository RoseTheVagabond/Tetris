#include "board.hpp"

Board::Board(Piece* pieces, sf::RenderWindow* window) : pieces(pieces), board(boardHeight, std::vector<int>(boardWidth)) {
    boardXPosition = window->getSize().x / 2 - boardWidth * blockSize / 2;
    boardYPosition = window->getSize().y / 2 - boardHeight * blockSize / 2;
    initBoard();
}

auto Board::initBoard() -> void {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            board[i][j] = EMPTY;
        }
    }
}

auto Board::storePiece(int y, int x, int piece, int rotation) -> void {
    for (int iBoard = y, i = 0; iBoard < i + blocksInPiece; iBoard++, i++) {
        for (int jBoard = x, j = 0; jBoard < j + blocksInPiece; jBoard++, j++) {
            if (pieces->getBlockType(piece, rotation, i, j) != EMPTY) {
                board[iBoard][jBoard] = FULL;
            }
        }
    }
}

auto Board::isGameOver() -> bool {
    for (int i = 0; i < boardWidth; i++) {
        if (board[0][i] == FULL) {
            return true;
        }
    }
    return false;
}

auto Board::removeRow(int rowNumber) -> void {
    for (int i = rowNumber; i > 0; i--) {
        for (int j = 0; j < boardWidth; j++) {
            board[i][j] = board[i - 1][j];
        }
    }
}

auto Board::isEmptyBlock(int y, int x) -> bool {
    return board[y][x] == EMPTY;
}

auto Board::isMovementPossible(int y, int x, int piece, int rotation) -> bool {
    for (int iBoard = y, i = 0; iBoard < i + blocksInPiece; iBoard++, i++) {
        for (int jBoard = x, j = 0; jBoard < j + blocksInPiece; jBoard++, j++) {
            if (pieces->getBlockType(piece, rotation, i, j) != EMPTY) {
                if (iBoard < 0 || iBoard >= boardHeight || jBoard < 0 || jBoard >= boardWidth) {
                    return false;
                }
                if (board[iBoard][jBoard] == FULL || board[iBoard][jBoard] == ROTATION) {
                    return false;
                }
                if (!isEmptyBlock(iBoard, jBoard)) {
                    return false;
                }
            }
        }
    }
    return true;
}

auto Board::getPiecePositionX(int piecePositionX) -> int {
    return boardXPosition + piecePositionX * blockSize;
}

auto Board::getPiecePositionY(int piecePositionY) -> int {
    return boardYPosition + piecePositionY * blockSize;
}
