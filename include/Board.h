#ifndef BOARD_H
#define BOARD_H

#include "Rules.h"
#include "Vec2.h"
#include <vector>

namespace Chess {
    class Board {
    public:
        Board();
        virtual ~Board();
        void reset();
        Piece getPiece(const Vec2& location) const;
        Piece getPiece(int x, int y) const;
        void set(Piece piece, Vec2 location);
        void move(Vec2 startPosition, Vec2 endPosition);
        std::vector<Vec2> getPiecePositions(Color color);
        void print();
    private:
        static const int BUFFER = 2;
        static const int WIDTH = 8;
        Piece squares[2*BUFFER + WIDTH][2*BUFFER + WIDTH];
        void initBounds();
    };
};

#endif // BOARD_H
