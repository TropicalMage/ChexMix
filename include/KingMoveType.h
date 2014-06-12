#ifndef KINGMOVETYPE_H
#define KINGMOVETYPE_H

#include "MoveType.h"

namespace Chess {
    class KingMoveType : public MoveType {
        public:
            KingMoveType();
            virtual ~KingMoveType();
        protected:
        private:
            virtual const std::vector<const Vec2*> getDirections() const;
            virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const;
            static const std::vector<const Vec2*> directions;
    };
};

#endif // KINGMOVETYPE_H
