#include "KingMoveType.h"
#include "Board.h"
#include "GameState.h"
#include "Vec2.h"

const std::vector<const Vec2*> Chess::KingMoveType::directions({
                                        new Vec2(1, 0), new Vec2(1, -1), new Vec2(0, -1),
                                        new Vec2(-1, -1), new Vec2(-1, 0), new Vec2(-1, 1),
                                        new Vec2(0, 1), new Vec2(1, 1)});

Chess::KingMoveType::KingMoveType() {
    maxIterations = 1;
}

Chess::KingMoveType::~KingMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::KingMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::KingMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const {
    return std::vector<Vec2>(0);
}
