#ifndef RULES_H
#define RULES_H

#include "Vec2.h"

namespace Chess {
    class MoveType;
    class Board;
    typedef char Piece;
    typedef char Color;
    typedef Vec2 Action;

    //Colors
    const Color WHITE = 1;
    const Color BLACK = 0;

    //Pieces
    const Piece WHITE_KING = 1;
    const Piece WHITE_QUEEN = 2;
    const Piece WHITE_BISHOP = 3;
    const Piece WHITE_KNIGHT = 4;
    const Piece WHITE_ROOK = 5;
    const Piece WHITE_PAWN = 6;

    const Piece BLACK_KING = -1;
    const Piece BLACK_QUEEN = -2;
    const Piece BLACK_BISHOP = -3;
    const Piece BLACK_KNIGHT = -4;
    const Piece BLACK_ROOK = -5;
    const Piece BLACK_PAWN = -6;

    const Piece EMPTY = 0;
    const Piece BOUNDARY = 7;

    //Utility
    const MoveType& getMoveType(Piece piece);
    inline bool areEnemies(Piece piece, Piece otherPiece) {
        return piece * otherPiece < 0;
    }
    inline Color getColor(Piece piece) {
        return piece > 0;
    }
    inline char getDirection(Color color) {
        return color*2 - 1;
    }
    inline Vec2 vec2FromId(char id) {
        return Vec2(id % 8, id / 8);
    }
    inline char getId(Vec2 value) {
        return value.x + (8*value.y);
    }
    //Encoding for Color or Piece (both are typedefs of char)
    inline char getId(Piece piece) {
        return piece;
    }
    inline char getOpposingColor(Color color) {
        bool temp = color;
        return !temp;
    }

};

#endif //RULES_H
