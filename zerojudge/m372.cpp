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
struct DSU {
	vector<int> fa;
	vector<int> sz;
	
	void init(int n) {
		fa.resize(n+5, 0);
		sz.resize(n+5, 1);
		for (int i = 0; i < n+5; ++i) {
			fa[i] = i;
		}
	}

	int query(int i) {
		if (i == fa[i]) return i;
		fa[i] = query(fa[i]);
		return fa[i];
	}
	
	void modify(int a, int b) {
		int pa = query(a);
		int pb = query(b);
		if (sz[pa] < sz[pb]) swap(pa, pb);
		fa[pb] = pa;
		sz[pa] += sz[pb];
	}
}


signed main(){_
	int n, m; 
	cin >> n >> m;
		

	return 0;
}
