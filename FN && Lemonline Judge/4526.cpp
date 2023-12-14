#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, INT_MAX);
const int mod = 1e9+7;

int pow(int a, int n) {
	int r = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

struct treap {
	int sz=0;
	int val;
	int chr;
	int pri;
	treap *l=nullptr;
	treap *r=nullptr;
	int key() {
		if (!l) return l.sz;
		return 0;
	}
	treap(char _chr) {
		_chr -= ('a' - 1);
		val = _chr;
		chr = _chr
		pri = dis(gen);
	}
}

treap* merge(treap *a, treap *b) {
	if (!a) return b;
	if (!b) return a;

	if (a->pri > b->pri) {
		a->r = merge(a->r, b);
		a->sz = a->l->sz + a->r->sz;
		a->val = (a->l->val) + pow(27, a->key())*chr%mod + pow(27, a->key() + 1)*(a->r->val)% mod;
		a->val %= mod;
		return a;
	}
	b->l = merge(a, b->l);
	b->sz = b->l->sz + b->r->sz;
	b->val = (b->l->val) + pow(27, b->key())*chr%mod + pow(27, b->key()+1)*(b->r->val) % mod;
	b->val %= mod;
	return b;
}

void split(node *s, 


signed main(){_
	string s;
	cin >> s;
	int q;
	cin >> q;


	return 0;
}
