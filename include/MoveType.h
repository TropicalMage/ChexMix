#ifndef MOVETYPE_H
#define MOVETYPE_H

#include <vector>

class Vec2;
namespace Chess {
    class Board;
    class GameState;

    class MoveType {
    public:
        std::vector<Vec2> generateMoves(const GameState& state, const Vec2& position) const;
    protected:
        int maxIterations;
    private:
        virtual const std::vector<const Vec2*> getDirections() const = 0;
        virtual std::vector<Vec2> getConditionalMoves(const GameState& state, const Vec2& position) const = 0;
    };
};

#endif // MOVETYPE_H
