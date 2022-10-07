#include <iostream>
#include <vector>
#include "node.h"
using namespace std;


Tic Node::get_val() { return this -> val; }

int Node::get_degree() { return this -> degree; }
		
int Node::get_x() { return this -> x; }
		
int Node::get_y() { return this -> y; }
		
vector<Node *> Node::get_neighbors() { return this -> neighbors; }

void Node::set_val(Tic val) { this -> val = val; }

void Node::add_neighbor(Node *n) { neighbors.push_back(n); degree++; }

void Node::set_location(int x, int y) { this -> x = x; this -> y = y; }

void connect(Node& a, Node& b) {
	a.add_neighbor(&a);
	b.add_neighbor(&b);
}

bool connected(Node& a, Node& b) { 
	for (vector<Node *>::iterator it = a.neighbors.begin(); it != a.neighbors.end(); ++it) {
		if (*it == &b)
			return true;
	}
	return false;
}
		
bool operator == (Node& a, Node& b) { return a.val == b.val; }

ostream& operator << (ostream& out, Node& n) {
	switch (n.val) {
		case Tic::O: out << "O"; break;
		case Tic::EMPTY: out << "."; break;
		case Tic::X: out << "X"; break;
	}
	return out;
}

