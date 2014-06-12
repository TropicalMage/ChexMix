#include "AIAgent.h"
#include "Director.h"
#include "Vec2.h"
#include "Rules.h"
#include "Board.h"

//Finish:
//States
//Corrections
//Based Time performance




Chess::AIAgent::AIAgent() {
    alpha = 0;
    beta = 0;
    MAX_DEPTH = 1;
}

Chess::AIAgent::~AIAgent() {
    //dtor
}

//#######################################################
//function ALPHA-BETA-SEARCH(state) returns an action
//v <- MAX-VALUE(state, −inf, +inf)
//return the action ACTIONS(state) with value v
//#######################################################
// Begins the search algorithm for an optimal action
Action Chess::AIAgent::alphaBetaSearch(State state) {
    return maxValue(state, color, MAX_DEPTH, -100, 100);
}

//#######################################################
//function MAX-VALUE(state, alpha, beta) returns a utility value
//if TERMINAL-TEST(state) then return UTILITY(state)
//v <- −inf
//for each a in ACTIONS(state) do
//v <- MAX(v, MIN-VALUE(RESULT(state, a), alpha, beta))
//if v >= beta then return v
//alpha <- MAX(alpha, v)
//return v
//#######################################################
// Returns action for the color that gives the max eval
Action Chess::AIAgent::maxValue(State state, Color color, char depth, char alpha, char beta) {
    char v = -100; // Utility value

    Action maxAction = Vec2();
    std::vector<Action> yourPossibleMoves = director->getValidMoves(state, color);
    for(Action move: yourPossibleMoves) {
        // You perform your trial-and-error move
        State newState = State(state);
        director->movePiece(newState, move);

        // The Max Function with/without recursion
        if(depth >= MAX_DEPTH) {
            char newEval = evaluateState(newState, color);
            if(newEval > v) {
                v = newEval;
                maxAction = move;
            }
        } else {
            // Your opponent performs the minimal counter-move
            Action minMove = minValue(newState, color, depth, alpha, beta);
            State minState = director->movePiece(newState, minMove);
            // Store the best-case for the minimum
            char minEval = evaluateState(minState, color);
            if(minEval > v) {
                v = minEval;
                maxAction = move;
            }
        }

        // Directly copying Pseudo-code
        if (v >= beta) {
            return minMove;
        }
        if(alpha < v) {
            alpha = v;
        }
    }
    return maxAction;
}

//#######################################################
//function MIN-VALUE(state, alpha, beta) returns a utility value
//if Terminal-Test(state) then return UTILITY(state)
//v <- +inf
//for each a in ACTIONS(state) do
//v <- MIN(v, MAX-VALUE(RESULT(state, a), alpha, beta))
//if v <= alpha then return v
//b <- MIN(beta, v)
//return v
//#######################################################
// Returns action for the color that gives the min eval with pruning
Action Chess::AIAgent::minValue(State state, Color color, char depth, char alpha, char beta) {
    depth++;
    char v = 100; // Utility value

    Action minAction = Vec2();
    std::vector<Action> opponentsPossibleMoves = director->getValidMoves(state, getOpposingColor(color));
    for(Action move: opponentsPossibleMoves) {
        // The evil man performs his trial-and-error move
        State newState = State(state);
        director->movePiece(newState, move);

        // You perform your maximum counter-move
        Action maxMove = maxValue(newState, color, depth, alpha, beta);
        State maxState = director->movePiece(newState, maxMove);
        // Store the best-case for the maximum
        char maxEval = evaluateState(maxState, color);
        if (maxEval < v) {
            v = maxEval;
            minAction = move;
        }

        // Directly copying Pseudo-code
        if (v <= alpha) {
            return maxMove;
        }
        if(beta > v) {
            beta = v;
        }
    }
    return minAction;
}

// Returns evaluation of a given state
char Chess::AIAgent::evaluateState(State state, Color color) {
    char grade;
    for(Vec2 square: state->getPiecePositions(color)) {
        grade += getWeight(state->getPiece(square);
    }
    for(Vec2 square: state->getPiecePositions(getOpposingColor(color))) {
        grade -= getWeight(state->getPiece(square);
    }
    return grade;
}

