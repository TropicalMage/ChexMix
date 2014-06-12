#include "Director.h"
#include <vector>
#include "Board.h"
#include <iostream>
#include "MoveType.h"
#include "GameState.h"

const char Chess::Director::defaultKingPositions[2] = {getId(Vec2(4,0)), getId(Vec2(4,7))};
const char Chess::Director::defaultRightRookPositions[2] = {getId(Vec2(0,7)), getId(Vec2(7,0))};
const char Chess::Director::defaultLeftRookPositions[2] = {getId(Vec2(0,0)), getId(Vec2(7,7))};

Chess::Director::Director(Board *board) : state(new GameState(board)) {
    //ctor
}

Chess::Director::~Director() {
    delete state;
}

//Retrieve all valid moves for a particular color
std::vector<Vec2> Chess::Director::getValidMoves(Color color) {
    std::vector<Vec2> moves;
    for(Vec2 position : state->getPiecePositions(color)) {
        std::vector<Vec2> pieceMoves = getMoveType(state->getPiece(position)).generateMoves(*state, position);
        moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
    }
    if(canCastleLeft(color)) {

    }
    std::cout << std::endl << "number of valid moves: " << moves.size();
    return moves;
}

//Execute a message string (recieved from server)
bool execute(std::string action) {
    return false;
}

//Castling checks
bool Chess::Director::canCastleRight(Color color) {
    int colorIndex = getId(color);
    if(state->hasMoved(defaultKingPositions[colorIndex])) return false;
    if(state->hasMoved(defaultRightRookPositions[colorIndex])) return false;
    for(int i = 0; i < 3; i++) {
        if(state->getPiece(defaultKingPositions[colorIndex] + i) != EMPTY) return false;
    }
    return true;
}
bool Chess::Director::canCastleLeft(Color color) {
    int colorIndex = getId(color);
    if(state->hasMoved(defaultKingPositions[colorIndex])) return false;
    if(state->hasMoved(defaultLeftRookPositions[colorIndex])) return false;
    for(int i = 0; i < 2; i++) {
        if(state->getPiece(defaultKingPositions[colorIndex] - i) != EMPTY) return false;
    }
    return true;
}
