#include "RookMoveType.h"
#include "Board.h"
#include "GameState.h"
#include "Vec2.h"

const std::vector<const Vec2*> Chess::RookMoveType::directions({
                                        new Vec2(1, 0), new Vec2(0, -1),
                                        new Vec2(-1, 0), new Vec2(0, 1)});

Chess::RookMoveType::RookMoveType() {
    maxIterations = 7;
}

Chess::RookMoveType::~RookMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::RookMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::RookMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const{
    return std::vector<Vec2>(0);
}
