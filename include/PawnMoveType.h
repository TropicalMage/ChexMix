#ifndef PAWNMOVETYPE_H
#define PAWNMOVETYPE_H

#include "MoveType.h"
#include "Board.h"
#include "GameState.h"
#include "Vec2.h"

namespace Chess {
    class PawnMoveType : public MoveType {
    public:
        PawnMoveType();
        virtual ~PawnMoveType();
    protected:
    private:
        virtual const std::vector<const Vec2*> getDirections() const;
        virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
        static const std::vector<const Vec2*> directions;
        bool canMoveForward(const GameState& state, const Vec2& position) const;
        bool canAttackRightDiagonal(const GameState& state, const Vec2& position) const;
        bool canAttackLeftDiagonal(const GameState& state, const Vec2& position) const;
        bool canEnPassantRightDiagonal(const GameState& state, const Vec2& position) const;
        bool canEnPassantLeftDiagonal(const GameState& state, const Vec2& position) const;
    };


    //inlines
    inline bool PawnMoveType::canMoveForward(const GameState& state, const Vec2& position) const {
        char direction = getDirection(getColor(state.getPiece(position)));
        return state.getPiece(Vec2(position.x, position.y + direction)) != BOUNDARY;
    }
    inline bool PawnMoveType::canAttackRightDiagonal(const GameState& state, const Vec2& position) const {
        char direction = getDirection(getColor(state.getPiece(position)));
        return areEnemies(state.getPiece(position), state.getPiece(position.x + 1, position.y + direction));
    }
    inline bool PawnMoveType::canEnPassantRightDiagonal(const GameState& state, const Vec2& position) const {
        char direction = getDirection(getColor(state.getPiece(position)));
        return state.canCroissant(Vec2(position.x + 1, position.y + direction));
    }
    inline bool PawnMoveType::canAttackLeftDiagonal(const GameState& state, const Vec2& position) const {
        char direction = getDirection(getColor(state.getPiece(position)));
        return areEnemies(state.getPiece(position), state.getPiece(position.x - 1, position.y + direction));
    }
    inline bool PawnMoveType::canEnPassantLeftDiagonal(const GameState& state, const Vec2& position) const {
        char direction = getDirection(getColor(state.getPiece(position)));
        return state.canCroissant(Vec2(position.x - 1, position.y + direction));
    }
};

#endif // PAWNMOVETYPE_H
