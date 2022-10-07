#include <iostream>
#include <string>
#include "tic.h"
using namespace std;

void Tic::assign(Tic::Value v) { this -> val = v; }

bool Tic::empty() { return val == Tic::Value::EMPTY; }

bool Tic::white() { return val == Tic::Value::WHITE; }

bool Tic::black() { return val == Tic::Value::BLACK; }

void Tic::operator = (string s) {
  if (s.compare("EMPTY") == 0)
    assign(Tic::Value::EMPTY);
  else if(s.compare("BLACK") == 0)
    assign(Tic::Value::BLACK);
  else if(s.compare("WHITE") == 0)
    assign(Tic::Value::WHITE);
  else
    exit(1);
}
		
Tic Tic::operator ! () {
	switch(val) {
		case Tic::Value::BLACK: assign(Tic::Value::WHITE); return *this;
		case Tic::Value::WHITE: assign(Tic::Value::BLACK); return *this;
		default: exit(1);
	}
}
		
bool Tic::operator == (Tic const &obj) { return val == obj.val; }

bool Tic::operator == (Tic::Value const &obj) { return val == obj; }
		
bool Tic::operator != (Tic const &obj) { return val != obj.val; }

bool Tic::operator != (Tic::Value const &obj) { return val != obj; }
		
ostream& operator << (ostream &o, const Tic &obj) {
	switch(obj.val) {
		case Tic::Value::EMPTY: o << "."; break;
		case Tic::Value::BLACK: o << "X"; break;
		case Tic::Value::WHITE: o << "O"; break;
		default: exit(1);
	}
	return o;
}