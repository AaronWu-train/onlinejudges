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
	int n;
	vector<int> fa;
	DSU (int _n) {
		n = _n;
		fa.resize(n + 5);
		for (int i = 0; i <= n+2; ++i) {
			fa[i] = i;
		}
	}
	int query(int a) {
		debug(a);
		if (fa[a] == a) return a;
		fa[a] = query(fa[a]);
		return fa[a];
	}
	void modify(int a, int b) {
		int da = query(a);
		int db = query(b);
		fa[db] = da;
		debug(da,db);
	}
};


signed main(){_
	int n, m;
	cin >> n >> m;
	DSU djs(n);	
	for (int i = 0; i < m; ++i) {
		int a, b;
	   	cin >> a >> b;
		djs.modify(a, b);
		debug(a, b);
	}
	vector<bool> head(n+5, 0);
	head[djs.query(1)] = 1;
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		auto f = djs.query(i);
		if(head[f] == false) {
			head[f] = true;
			ans.pb(f);
		}
	}
	cout << ans.size() << endl;
	for (auto &i : ans) {
		cout << djs.query(1) << " " << i << endl;
	}

	return 0;
}
