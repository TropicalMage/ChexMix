#include "QueenMoveType.h"
#include "Board.h"
#include "GameState.h"
#include "Vec2.h"

const std::vector<const Vec2*> Chess::QueenMoveType::directions({
                                        new Vec2(1, 0), new Vec2(1, -1), new Vec2(0, -1),
                                        new Vec2(-1, -1), new Vec2(-1, 0), new Vec2(-1, 1),
                                        new Vec2(0, 1), new Vec2(1, 1)});

Chess::QueenMoveType::QueenMoveType() {
    maxIterations = 7;
}

Chess::QueenMoveType::~QueenMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::QueenMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::QueenMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const{
    return std::vector<Vec2>(0);
}
