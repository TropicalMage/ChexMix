#include "BishopMoveType.h"

const std::vector<const Vec2*> Chess::BishopMoveType::directions({
                                        new Vec2(1, -1), new Vec2(-1, -1),
                                        new Vec2(-1, 1), new Vec2(1, 1)});

Chess::BishopMoveType::BishopMoveType() {
    maxIterations = 7;
}

Chess::BishopMoveType::~BishopMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::BishopMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::BishopMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const {
    return std::vector<Vec2>(0);
}
