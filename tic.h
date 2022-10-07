#ifndef TIC_H
#define TIC_H

#include <iostream>
#include <string>
using namespace std;

class Tic {
	public:
		enum Value { EMPTY, WHITE, BLACK };
		Tic() { assign(Value::EMPTY); }
        Tic(Tic const &t) : val(t.val) {}
        Tic(Tic::Value v) : val(v) {}
		Tic(string s) { *this = s; }
		void assign(Value);
        bool empty();
        bool white();
        bool black();
		void operator = (string);
		Tic operator ! ();
		bool operator == (Tic const &);
        bool operator == (Value const &);
		bool operator != (Tic const &);
        bool operator != (Value const &);
		friend ostream& operator << (ostream &, const Tic &);
	private:
		Value val;
};


#endif