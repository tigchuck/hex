#ifndef HEXBOARD_H
#define HEXBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "tic.h"
using namespace std;

class HexBoard {
	private:
		int size;
		vector<Tic> tiles;
		vector< vector<int> > edges;
	public:
		HexBoard(int);
		void set_tile(string, int);
		void set_tile(Tic const &, int);
		void set_tile(string, int, int);
		void set_tile(Tic const &, int, int);
		int get_row(int);
		int get_col(int);
		int get_tile(int, int);
		bool is_tile(int, int);
		int get_size();
		Tic get_tic(int);
		Tic get_tic(int, int);
		vector<Tic> get_tiles();
		vector<int> get_edges(int);
		void reset(vector<Tic>);
		void print();
};


#endif