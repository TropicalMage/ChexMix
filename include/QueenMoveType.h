#ifndef QUEENMOVETYPE_H
#define QUEENMOVETYPE_H

#include "MoveType.h"

namespace Chess {
    class QueenMoveType : public MoveType {
    public:
        QueenMoveType();
        virtual ~QueenMoveType();
    protected:
    private:
        virtual const std::vector<const Vec2*> getDirections() const;
        virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
        static const std::vector<const Vec2*> directions;
    };
};

#endif // QUEENMOVETYPE_H
