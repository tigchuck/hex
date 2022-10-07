#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "game.h"
#include "hexboard.h"
#include "tic.h"
using namespace std;

void Game::run() {
    int x, y, i;
    board.print();
    while (!over()) {
        if (turn.white()) {
            move(x, y);
            board.set_tile(turn, x, y);
        } else {
            i = simulate();
            board.set_tile(turn, i);
        }
        board.print();
        !turn;
    }
}

void Game::move(int& x, int& y) {
    cout << "Move: ";
    cin >> x >> y;
    while (!legal_move(x, y)) {
        cout << "Illegal move." << endl;
        move(x, y);
    }
}

bool Game::legal_move(int x, int y) { return board.is_tile(x, y) && board.get_tic(x, y).empty(); }

bool Game::over() {
    if (!turn.white())  // checks after turn is switched
        return white_win();
    else 
        return black_win();
}

bool Game::white_win() {    // wins left to right
    vector<int> u = union_path(Tic::Value::WHITE);
    int size = board.get_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int index1 = board.get_tile(i, 0), index2 = board.get_tile(j, size - 1);
            if (board.get_tic(index1).white() && u[index1] == u[index2])
                return true;
        }
    }
    return false;
}

bool Game::black_win() {    // wins top to bottom
    vector<int> u = union_path(Tic::Value::BLACK);
    int size = board.get_size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int index1 = board.get_tile(0, i), index2 = board.get_tile(size - 1, j);
            if (board.get_tic(index1).black() && u[index1] == u[index2])
                return true;
        }
    }
    return false;
}

vector<int> Game::union_path(Tic::Value t) {
    int i = 0, size = board.get_size(), node; 
    vector<int> u (size * size, -1), stack = {};
    while (i < size * size) {
        if (board.get_tic(i) != t || u[i] != -1) { i++; continue; }
        stack.push_back(i);
        while (!stack.empty()) {
            node = stack[stack.size() - 1];
            stack.pop_back();
            u[node] = i;
            vector<int> edges = board.get_edges(node);
            for (auto it = begin(edges); it != end(edges); ++it) {
                if (u[*it] == -1 && board.get_tic(*it) == t)
                    stack.push_back(*it);
            }
        }
        i++;
    }
    return u;
}

int Game::simulate() {
    const int SIMS = 10000;
    int size = board.get_size() * board.get_size();
    Tic t = turn;
    vector<Tic> b = board.get_tiles();
    vector<int> order(size), wins(size, 0);
    for (int i = 0; i < size; ++i) 
        order[i] = i;
    
    auto rng = default_random_engine {};
    for (int i = 0; i < size; ++i) {
        if (!board.get_tic(i).empty()) { continue; }
        for (int s = 0; s < SIMS; ++s) {
            shuffle(begin(order), end(order), rng);
            board.set_tile(t, i);
            !t;
            for (auto it = begin(order); it != end(order); ++it) {
                if (board.get_tic(*it).empty()) { board.set_tile(t, *it); !t; }
            }
            if ((turn == Tic::Value::WHITE && white_win()) || (turn == Tic::Value::BLACK && black_win())) { wins[i]++; }
            board.reset(b);
            t = turn;
        }
    }

    int index = 0, max = wins[0];
    for (int i = 1; i < wins.size(); ++i) {
        if (wins[i] > max || !board.get_tic(index).empty()) { index = i; max = wins[i]; }
    }
    return index;
}