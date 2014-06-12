#include "GameState.h"

Chess::GameState::GameState(Board *board) : board(board), hasLocationMoved({false}) {
    //ctor
}

Chess::GameState::~GameState() {
    //dtor
}
