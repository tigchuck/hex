#include <iostream>
#include <vector>
#include <string>
#include "tic.h"
#include "hexboard.h"
using namespace std;

HexBoard::HexBoard(int size) : size(size), tiles(size * size, Tic()), edges(size * size, vector<int> (0, 0)) {
	const vector< vector<int> > neighbors = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1} };
	for (int i = 0; i < size * size; ++i) {
		int x = get_row(i), y = get_col(i);
		for (auto it = begin(neighbors); it != end(neighbors); ++it) {
			if (is_tile(x + (*it)[0], y + (*it)[1]))
				edges[i].push_back(get_tile(x + (*it)[0], y + (*it)[1]));
		}
	}
}
 
void HexBoard::set_tile(string s, int i) { tiles[i] = s; }

void HexBoard::set_tile(Tic const &t, int i) { tiles[i] = t; }

void HexBoard::set_tile(string s, int x, int y) { int i = get_tile(x, y); tiles[i] = s; }

void HexBoard::set_tile(Tic const &t, int x, int y) {int i = get_tile(x, y); tiles[i] = t; }

int HexBoard::get_row(int i) { return i / size; }

int HexBoard::get_col(int i) { return i % size; }

int HexBoard::get_tile(int x, int y) { return (x * size) + y; }

bool HexBoard::is_tile(int x, int y) { return x >= 0 && x < size && y >= 0 && y < size; }

int HexBoard::get_size() { return this -> size; }

Tic HexBoard::get_tic(int i) { return tiles[i]; }

Tic HexBoard::get_tic(int x, int y) { int i = get_tile(x, y); return tiles[i]; }

vector<Tic> HexBoard::get_tiles() { return tiles; }

vector<int> HexBoard::get_edges(int i) { return edges[i]; }

void HexBoard::reset(vector<Tic> t) { if (t.size() == size * size) tiles = t; }

void HexBoard::print() {
	auto tab = [] (int i) -> void { for (int k = 0; k < i; ++k) cout << "  "; };

	for (int x = 0; x < size; ++x) {
		tab(x);
		for (int y = 0; y < size - 1; ++y) 
			cout << get_tic(x, y) << " - ";
		cout << get_tic(x, size - 1) << endl;
		if (x < size - 1) {
			tab(x); cout << " \\ ";
			for (int i = 0; i < size - 1; ++i) 
                		cout << "/ \\ ";
		}
        cout << endl;
	}
}