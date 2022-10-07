#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

enum class Tic { O = -1, EMPTY = 0, X = 1 };

class Node {
	private:
		Tic val;
		int degree, x, y;
		vector<Node *> neighbors;
	public:
		Node() : x(0), y(0), val(Tic::EMPTY), degree(0), neighbors() {};
		Node(const Node& n) : x(n.x), y(n.y), val(n.val), degree(n.degree), neighbors(n.neighbors) {};
		Node(int x, int y) : x(x), y(y), val(Tic::EMPTY), degree(0), neighbors() {};
		Tic get_val();
		int get_degree();
		int get_x();
		int get_y();
		vector<Node *> get_neighbors();
		void set_val(Tic);
		void add_neighbor(Node *);
		void set_location(int, int);
		friend void connect(Node&, Node&);
		friend bool connected(Node&, Node&);
		friend bool operator == (Node&, Node&);
		friend ostream& operator << (ostream&, Node&);
};


#endif