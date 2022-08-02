#include "lib1168.h"
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxn = 1e6+5;


struct node{
    int val, id;
    bool operator < (const node &b) const {return val < b.val;}
};

struct heap{
    node v[maxn];
    int sz;
    void push(node x) {
        v[sz++] = x;
        std::push_heap(v, v+sz);
    }
    node top() {
        return v[0];
    }
    void pop() {
        std::pop_heap(v,v+sz);
        --sz;
    }
}mx, mn;

int total = 0;
bool poped[maxn] = {0};

void pop_big() {
    while (poped[mx.top().id]) mx.pop();
    poped[mx.top().id] = 1;
    mx.pop();
}

void pop_small() {
    while (poped[mn.top().id]) mn.pop();
    poped[mn.top().id] = 1;
    mn.pop();
}

void push(int s) {
    mx.push({s, total});
    mn.push({-s, total});
    total++;
}

int big() {
    while(poped[mx.top().id]) mx.pop();
    return mx.top().val;
}

int small() {
    while(poped[mn.top().id]) mn.pop();
    return -mn.top().val;
}
