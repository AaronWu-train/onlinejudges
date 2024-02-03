#include "lib0046.h"

// definition of operations (already defined in header)
// const int OP_LESS = 0;
// const int OP_LEQ = 1;
// const int OP_GREATER = 2;
// const int OP_GEQ = 3;

// const int OP_AND = 0;
// const int OP_OR = 1;
// const int OP_XOR = 2;
// const int OP_ADD = 3;
// const int OP_SUBTRACT = 4;

// constant strings that might be useful
std::string zero_str = "00000000000000000000000000000000";
std::string one_str = "00000000000000000000000010000000";
std::string sign_str = "00000000000000000000000000000001";
std::string full_str = "11111111111111111111111111111111";
std::string unit_str = "10000000000000000000000000000000";

void solve(int problem_type) {
	if (problem_type == 1) { 		// double
		left(0, 1, 1);
		calculate(0, 1, OP_OR, 2);
		print(2);
		answer(1);
	} else if (problem_type == 2) { // square
		for (int i = 0; i < 32; ++i) {
			prop(0, i, 1);
			print(0);
			print(1);
			calculate(0, 1, OP_AND, 2);
			print(2);
			if (i <= 24) right(2, 24-i, 3);
			else if (i > 24) left(2, i-24, 3);
			print(3);
			calculate(3, 10, OP_ADD, 10);
			print(10);
		}	

		answer(10);
	} else if (problem_type == 3) { // sine

	} else { 						// log
			 
	}
}
