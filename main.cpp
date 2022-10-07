#include <iostream>
#include <vector>
#include <string>
#include "tic.h"
#include "hexboard.h"
#include "game.h"
using namespace std;

int main() {
    Game game(5);
    game.run();
    return 0;
}