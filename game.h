#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "hexboard.h"
using namespace std;

class Game {
	private:
                HexBoard board;
                Tic turn;
	public:
		Game(int size) : board(size), turn(Tic::Value::WHITE) {};
                void run();
                void move(int&, int&);
                bool legal_move(int, int);
                bool over();
                bool white_win();
                bool black_win();
                vector<int> union_path(Tic::Value);  
                int simulate();           
};

#endif