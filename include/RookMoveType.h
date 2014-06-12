#ifndef ROOKMOVETYPE_H
#define ROOKMOVETYPE_H

#include "MoveType.h"

namespace Chess {
    class RookMoveType : public MoveType {
    public:
        RookMoveType();
        virtual ~RookMoveType();
    protected:
    private:
        virtual const std::vector<const Vec2*> getDirections() const;
        virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
        static const std::vector<const Vec2*> directions;
    };
};

#endif // ROOKMOVETYPE_H
