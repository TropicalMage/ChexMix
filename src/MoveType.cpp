#include "MoveType.h"
#include "Board.h"
#include "GameState.h"
#include <iostream>
#include "Vec2.h"
#include "Rules.h"
#include <cmath>

std::vector<Vec2> Chess::MoveType::generateMoves(const GameState& state, const Vec2& position) const {
    std::cout << std::endl << std::endl << "Generating moves for position: (" << (int)position.x << ", " << (int)position.y << ") ...";
    std::vector<Vec2> moves;
    Piece current = state.getPiece(position);

    //For each possible direction, get available moves
    for(const Vec2* direction : this->getDirections()) {
        std::cout << std::endl << "direction: (" << (int)direction->x << ", " << (int)direction->y << ") ... ";
        bool collided = false;
        //For sliding pieces, keep checking forward until a collision with another unit
        for(int i = 1; !collided && i <= this->maxIterations; i++) {
            Piece other = state.getPiece(Vec2(position.x + direction->x*i, position.y + direction->y*i));
            collided = (other != Chess::EMPTY);
            if(!collided || Chess::areEnemies(current, other)) {
                Vec2 end(position.x + direction->x*i, position.y + direction->y*i);
                moves.push_back(Vec2(Chess::getId(position), Chess::getId(end)));
            }
        }
    }
    //Add conditional moves
    for(Vec2 move : this->getConditionalMoves(state, position)) {
        moves.push_back(move);
    }
    std::cout << std::endl << "positions generated: " << moves.size() << std::endl;
    return moves;
}

//Default
std::vector<Vec2> Chess::MoveType::getConditionalMoves(const GameState& state, const Vec2& position) const {
    return std::vector<Vec2>(0);
}
