#ifndef BISHOPMOVETYPE_H
#define BISHOPMOVETYPE_H

#include "Vec2.h"
#include <vector>
#include "MoveType.h"

namespace Chess {
    class BishopMoveType : public MoveType {
        public:
            BishopMoveType();
            virtual ~BishopMoveType();
        protected:
        private:
            virtual const std::vector<const Vec2*> getDirections() const;
            virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
            static const std::vector<const Vec2*> directions;
    };
};

#endif // BISHOPMOVETYPE_H
