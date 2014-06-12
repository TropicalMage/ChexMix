#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Vec2.h"
#include "Rules.h"
#include "Board.h"

namespace Chess {
    class GameState {
    public:
        GameState(Board *board);
        virtual ~GameState();
        Piece getPiece(Vec2 position) const;
        Piece getPiece(int x, int y) const;
        Piece getPiece(char position) const;
        void movePiece(Vec2 start, Vec2 end);
        void movePiece(char start, char end);
        std::vector<Vec2> getPiecePositions(Color color) const;
        bool hasMoved(Vec2 position) const;
        bool hasMoved(char position) const;
        bool canCroissant(Vec2 position) const;
        void printBoard();
    protected:
    private:
        Board* board;
        bool hasLocationMoved[64];
        bool isCrossaintable[64];
        bool vulnerablePosition[64];
        char croissantPosition;
        bool kingWasChecked[2];
    };

    //Print the board to command prompt
    inline void Chess::GameState::printBoard() {
        board->print();
    }
    //Has a position been moved since the game began
    inline bool GameState::hasMoved(Vec2 position) const{
        return hasLocationMoved[(int)getId(position)];
    }
    inline bool GameState::hasMoved(char position) const{
        return hasLocationMoved[(int)position];
    }
    //Get Piece
    inline Piece GameState::getPiece(Vec2 position) const {
        return board->getPiece(position.x, position.y);
    }
    inline Piece GameState::getPiece(char position) const {
        return board->getPiece(vec2FromId(position));
    }
    inline Piece GameState::getPiece(int x, int y) const {
        board->getPiece(x, y);
    }
    //Move Piece
    inline void GameState::movePiece(Vec2 start, Vec2 end) {
        movePiece(getId(start), getId(end));
    }
    inline void GameState::movePiece(char start, char end) {
        //move the piece
        board->move(vec2FromId(start), vec2FromId(end));
    }
    //get piece positions of a particular color
    inline std::vector<Vec2> GameState::getPiecePositions(Color color) const{
        return board->getPiecePositions(color);
    }
    //Can a pawn move to position by an en passant
    inline bool GameState::canCroissant(Vec2 position) const {
        return isCrossaintable[getId(position)];
    }
    inline void positionIsCroissantable(Vec2 &position, bool croissantable = true) {
        isCrossaintable[getId(position)] = croissantable;
    }
};
#endif // GAMESTATE_H
