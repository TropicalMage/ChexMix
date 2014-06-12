#include <iostream>
#include <string>
#include <vector>
#include "Rules.h"
#include "Director.h"
#include "MoveType.h"
#include "Vec2.h"
#include "Board.h"
#include "AIAgent.h"

int main(int argc, const char **argv) {
    using namespace std;
    cout << "Program start" << std::endl;
    Chess::Board board;
    Chess::Director director(&board);
    director.printBoard();
    std::cout << endl;

    director.movePiece(Vec2(0, 1), Vec2(0, 2));
    director.printBoard();
    return 0;
}
