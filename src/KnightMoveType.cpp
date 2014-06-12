#include "KnightMoveType.h"
#include "Board.h"
#include "GameState.h"
#include "Vec2.h"

const std::vector<const Vec2*> Chess::KnightMoveType::directions({
                                        new Vec2(2, 1), new Vec2(2, -1), new Vec2(-2, 1),
                                        new Vec2(-2, -1), new Vec2(1, 2), new Vec2(1, -2),
                                        new Vec2(-1, 2), new Vec2(-1, -2)});

Chess::KnightMoveType::KnightMoveType() {
    maxIterations = 1;
}

Chess::KnightMoveType::~KnightMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::KnightMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::KnightMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const {
    return std::vector<Vec2>();
}
