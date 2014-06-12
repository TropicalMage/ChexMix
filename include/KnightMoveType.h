#ifndef KNIGHTMOVETYPE_H
#define KNIGHTMOVETYPE_H

#include "MoveType.h"

namespace Chess {
    class KnightMoveType : public MoveType {
    public:
        KnightMoveType();
        virtual ~KnightMoveType();

    protected:
    private:
        virtual const std::vector<const Vec2*> getDirections() const;
        virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
        static const std::vector<const Vec2*> directions;
    };
};

#endif // KNIGHTMOVETYPE_H
