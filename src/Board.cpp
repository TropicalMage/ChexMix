#include "Board.h"
#include "Vec2.h"
#include <iostream>
#include <cmath>

Chess::Board::Board() {
    initBounds();
    this->reset();
}

Chess::Board::~Board() {
    //dtor
}

//reset board
void Chess::Board::reset() {
    //White pieces
    set(WHITE_ROOK, Vec2(0,0));
    set(WHITE_KNIGHT, Vec2(1,0));
    set(WHITE_BISHOP, Vec2(2,0));
    set(WHITE_QUEEN, Vec2(3,0));
    set(WHITE_KING, Vec2(4,0));
    set(WHITE_BISHOP, Vec2(5,0));
    set(WHITE_KNIGHT, Vec2(6,0));
    set(WHITE_ROOK, Vec2(7,0));
    for(int i = 0; i < 8; i++) {
        set(WHITE_PAWN, Vec2(i, 1));
    }
    //Blanks spots
    for(int i = 0; i < 8; i++) {
        for(int j = 2; j < 6; j++) {
            set(EMPTY, Vec2(i,j));
        }
    }
    //Black pieces
    for(int i = 0; i < 8; i++) {
         set(BLACK_PAWN, Vec2(i, 6));
    }
    set(BLACK_ROOK, Vec2(0,7));
    set(BLACK_KNIGHT, Vec2(1,7));
    set(BLACK_BISHOP, Vec2(2,7));
    set(BLACK_QUEEN, Vec2(3,7));
    set(BLACK_KING, Vec2(4,7));
    set(BLACK_BISHOP, Vec2(5,7));
    set(BLACK_KNIGHT, Vec2(6,7));
    set(BLACK_ROOK, Vec2(7,7));
}

//Get piece given its location (on the playable area)
Chess::Piece Chess::Board::getPiece(const Vec2& location) const {
    //Acount for buffer (out of bounds) spots surrounding playable area
    return squares[(int)location.x + BUFFER][(int)location.y + BUFFER];
}

//Get piece given its location (on the playable area)
Chess::Piece Chess::Board::getPiece(int x, int y) const {
    //Acount for buffer (out of bounds) spots surrounding playable area
    return squares[(int)x + BUFFER][(int)y + BUFFER];
}

//set a piece to a location (on the playable area)
void Chess::Board::set(Piece piece, Vec2 location) {
    //Acount for buffer (out of bounds) spots surrounding playable area
    squares[(int)location.x + BUFFER][(int)location.y + BUFFER] = piece;
}

//Move a piece
void Chess::Board::move(Vec2 startPosition, Vec2 endPosition) {
    set(getPiece(startPosition), endPosition);
    set(EMPTY, startPosition);
}

//Get all positions containing a particular color's piece
std::vector<Vec2> Chess::Board::getPiecePositions(Color color) {
    std::vector<Vec2> positions;
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(Chess::getColor(getPiece(i, j)) == color) {
                positions.push_back(Vec2(i, j));
            }
        }
    }
    std::cout << std::endl << "units: " << positions.size();
    return positions;
}

//print board layout
void Chess::Board::print() {
    std::cout << std::endl << "- - - - - - - - - - -" << std::endl;
    for(int i = 0; i < WIDTH; i++) {
        std::cout << "- ";
        for(int j = 0; j < WIDTH; j++) {
            std::cout << (int) getId(getPiece(i, j)) << " ";
        }
    std::cout << "-" << std::endl;
    }
    std::cout << "- - - - - - - - - - -" << std::endl;
}

void Chess::Board::initBounds() {
    int WIDTH = 8;
    int BUFFER = 2;
    //Top
    for(int i = 0; i < WIDTH + 2*BUFFER; i++) {
        for(int j = WIDTH + BUFFER; j < WIDTH + 2*BUFFER; j++) {
            squares[i][j] = BOUNDARY;
        }
    }
    //Left
    for(int i = 0; i < BUFFER; i++) {
        for(int j = 0; j < WIDTH + 2*BUFFER; j++) {
            squares[i][j] = BOUNDARY;
        }
    }
    //Bottom
    for(int i = 0; i < WIDTH + 2*BUFFER; i++) {
        for(int j = 0; j < BUFFER; j++) {
            squares[i][j] = BOUNDARY;
        }
    }
    //Right
    for(int i = WIDTH + BUFFER; i < WIDTH + 2*BUFFER; i++) {
        for(int j = 0; j < WIDTH + 2*BUFFER; j++) {
            squares[i][j] = BOUNDARY;
        }
    }
}
