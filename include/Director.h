#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include <vector>
#include "Rules.h"
#include <iostream>
#include "GameState.h"

namespace Chess {
    class GameState;

    class Director {
    public:
        Director(Board *board);
        virtual ~Director();
        std::vector<Vec2> getValidMoves(Color color);
        bool execute(std::string action);
        void printBoard();
        void movePiece(Vec2 start, Vec2 end);
    protected:
    private:
        GameState *state;
        const static char defaultKingPositions[2];
        const static char defaultLeftRookPositions[2];
        const static char defaultRightRookPositions[2];
        bool canCastleRight(Color color);
        bool canCastleLeft(Color color);
    };

    inline void Director::movePiece(Vec2 start, Vec2 end) {

    }
    inline void execute(Vec2 action) {
        bool isCroissanting, isLunging, isCastlingLeft, isCastlingRight;
        extractFlags(action, isCroissanting, isLunging, isCastlingLeft, isCastlingRight);

        //reset whether a unit can en passant
        positionIsCroissantable()

        if(isCroissanting(start, end)) {
            state->set(EMPTY, vec2FromId(vulnerablePosition[croissantPosition]));
        } else {
            //croissant position is the halfway point (will be zero if not croissantable)
            croissantPosition = ((start + end) / 2) * croissantableMove;
            //store the position of the now vulnerable pawn (position will be zero if pawn is not vulnerable)
            vulnerablePosition[croissantPosition] = end*croissantableMove;
            //store whether the position is crossaintable
            isCrossaintable[croissantPosition] = croissantableMove;
        }
    }

    inline void Director::printBoard() {
        state->printBoard();
    }
    inline void extractFlags(Vec2 action, bool &croissant, bool &lunge, bool &castleLeft, bool &castleRight) {
        croissant = (start / 64) % 2;
        lunge = (start / 128) % 2;
        castleLeft = (end / 64) % 2;
        castleRight = (end / 128) % 2;
    }
};

#endif // DIRECTOR_H
