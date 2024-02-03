#ifndef ABACUS_H
#define ABACUS_H
#include <vector>
#include <string>

void solve(int problem_type);
void store(std::string s, int t);
void storebit(int x, int b, int t, int d);
void prop(int x, int b, int t);
void flip(int x, int t);
void left(int x, int p, int t);
void right(int x, int p, int t);
void compare(int x, int y, int cmp, int t);
void calculate(int x, int y, int op, int t);
void print(int x);
void printstr(int x);
void answer(int x);

const int OP_AND = 0;
const int OP_OR = 1;
const int OP_XOR = 2;
const int OP_ADD = 3;
const int OP_SUBTRACT = 4;

const int OP_LESS = 0;
const int OP_LEQ = 1;
const int OP_GREATER = 2;
const int OP_GEQ = 3;

#endif
