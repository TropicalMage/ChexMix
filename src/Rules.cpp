#include <cmath>
#include "Rules.h"
#include "MoveType.h"
#include "KingMoveType.h"
#include "QueenMoveType.h"
#include "BishopMoveType.h"
#include "KnightMoveType.h"
#include "RookMoveType.h"
#include "PawnMoveType.h"


namespace {
    using namespace Chess;
    const MoveType* const kingMoveType = new KingMoveType();
    const MoveType* const queenMoveType = new QueenMoveType();
    const MoveType* const bishopMoveType = new BishopMoveType();
    const MoveType* const knightMoveType = new KnightMoveType();
    const MoveType* const rookMoveType = new RookMoveType();
    const MoveType* const pawnMoveType = new PawnMoveType();

    const MoveType* const MOVE_TYPES[6] = {kingMoveType, queenMoveType, bishopMoveType,
                                            knightMoveType, rookMoveType, pawnMoveType};
    const char const PIECE_WEIGHT[6] = {50, 9, 3, 3, 5, 1};
}

const MoveType& Chess::getMoveType(Piece piece) {
    return *MOVE_TYPES[(int)std::abs(piece) - 1];
}

const char Chess::getWeight(Piece piece) {
    return PIECE_WEIGHT[(int)std::abs(piece) - 1];
}
