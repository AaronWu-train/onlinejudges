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
int n, q;

struct Query {
	int id;
	int ql;
	int qr;
	bool operator < (const Query &b) const {
        if (ql/k == b.ql/k) return qr < b.qr;
        return ql/k < b.ql/k;
    }
}

struct Trie {
	Trie* c[2];

	void add(int x) {
		Trie* cur = this;
		for (int i = 30; i >= 0; i--) {
			bool k = (x >> i & 1);
			if (cur->c[k] == nullptr) cur->c[k] = new Trie;
			cur = cur->c[k];
		}
	}

	int query(int x) {
		int ret = 0;
		Trie* cur = this;
		for (int i = 30; i >= 0; i--) {
			bool k = (x >> i & 1);
			if (cur->c[!k] != nullptr) {
				ret += 1<<i;
				cur = cur->c[!k];
			} else {
				cur = cur->c[k];
			}
		}
	}
}

vector<int> arr;
vector<Query> qlist;

void add(int p) {
	
}

signed main(){_
	cin >> n >> q;
	arr.resize(n+5);
	qlist.resize(q);
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		cin >> qlist[i].ql >> qlist[i].qr;
		qlist[i].id = i;
	}
	sort(AI(qlist));

	return 0;
}
