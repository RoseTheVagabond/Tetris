#include "board.cpp"
#include "pieces.cpp"
#include <SFML/Graphics.hpp>

int const waitTime = 700;

struct Game {

    int screenHeight = 0;
    Board* board;
    Piece* pieces;
    IO* io;

    //current piece:
    int currentPieceType = 0;
    int currentPieceRotation = 0;
    int currentPieceX = 0;
    int currentPieceY = 0;

    //next piece:
    int nextPieceType = 0;
    int nextPieceRotation = 0;
    int nextPieceX = 0;
    int nextPieceY = 0;


    Game(Board* board, Piece* pieces, IO* io, sf::RenderWindow* window) : board(board), pieces(pieces), io(io) {
        screenHeight = window->getSize().y;
    }

    auto getRandomNumber(int min, int max) -> int {
        std::srand(static_cast<int>(std::time(nullptr)));
        int randomNumber = min + std::rand() % (max - min + 1);
        return randomNumber;
    }

    auto initGame() -> void {
        srand((unsigned int) time(NULL));
        currentPieceType = getRandomNumber(0, 6);
        currentPieceRotation = getRandomNumber(0, 3);
        currentPieceX = (board->boardWidth / 2) + pieces->getInitialPosition(currentPieceType, currentPieceRotation)[1];
        currentPieceY = (board->boardWidth / 2) + pieces->getInitialPosition(currentPieceType, currentPieceRotation)[0];

        nextPieceType = getRandomNumber(0, 6);
        nextPieceRotation = getRandomNumber(0, 3);
        nextPieceX = board->boardWidth + 5;
        nextPieceY = 5;
    }

    auto createNewPiece() -> void {
        currentPieceType = nextPieceType;
        currentPieceRotation = nextPieceRotation;

        nextPieceType = getRandomNumber(0, 6);
        nextPieceRotation = getRandomNumber(0, 3);
    }

    auto drawPiece(int y, int x, int pieceType, int rotation) -> void {
        sf::Color colour;

        int pixelsX = board->getPiecePositionX(x);
        int pixelsY = board->getPiecePositionY(y);

        for(int i = 0; i < board->blocksInPiece; i++) {
            for(int j = 0; j < board->blocksInPiece; j++) {
                if(pieces->getBlockType(pieceType, rotation, i, j) == 1)
                    colour = sf::Color(255, 183, 3);
                else if(pieces->getBlockType(pieceType, rotation, i, j) == 2)
                    colour = sf::Color(251, 133, 0);

                if(pieces->getBlockType(pieceType, rotation, i, j) != 0) {
                    io->drawRectangle(pixelsX + j * board->blockSize,
                                      pixelsY + i * board->blockSize,
                                      (pixelsX + j * board->blockSize) + board->blockSize - 1,
                                      (pixelsY + i * board->blockSize) + board->blockSize - 1,
                                      colour);
                }
            }
        }
    }

    auto drawBoard() -> void {

    }

};
