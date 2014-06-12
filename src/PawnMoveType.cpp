#include "PawnMoveType.h"

const std::vector<const Vec2*> Chess::PawnMoveType::directions;

Chess::PawnMoveType::PawnMoveType() {
    maxIterations = 1;
}

Chess::PawnMoveType::~PawnMoveType() {
    //dtor
}

const std::vector<const Vec2*> Chess::PawnMoveType::getDirections() const {
    return directions;
}

std::vector<Vec2> Chess::PawnMoveType::getConditionalMoves(const GameState& state, const Vec2& position) const{
    std::vector<Vec2> moves;
    char direction = Chess::getDirection(getColor(state.getPiece(position)));
    //move forward check
    if(this->canMoveForward(state, position)) {
        moves.push_back(Vec2(position.x, position.y + direction));
    }
    //move 2 spaces forward check
    if(!state.hasMoved(position)) {
        moves.push_back(Vec2(position.x + 64, position.y + 2*direction));
    }
    //move diagonal checks
    if(canAttackRightDiagonal(state, position)) {
        moves.push_back(Vec2(position.x + 1, position.y + direction));
    }
    if(canAttackLeftDiagonal(state, position)) {
        moves.push_back(Vec2(position.x - 1, position.y + direction));
    }
    //EnPassant checks
    if(canEnPassantRightDiagonal(state, position)) {
        moves.push_back(Vec2(position.x + 1, position.y + direction + 64));
    }
    if(canEnPassantLeftDiagonal(state, position)) {
        moves.push_back(Vec2(position.x - 1, position.y + direction + 64));
    }
    return moves;
}
