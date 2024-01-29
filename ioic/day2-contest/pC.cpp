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
	vector<int>p;
	vector<int>rk;
	int size=0;
	void init(int n) {
		p.resize(n+1);
		rk.resize(n+1);
		size = n;
		for (int i = 1; i <= n; ++i) {
			p[i] = -1; rk[i] = 1;
		}
	}
	int find(int x) {
		if (p[x] < 0) return x;
		return p[x] = find(p[x]);
	}
	void uni(int a, int b) {
		a = find(a); b = find(b);
		if(a==b) return;
		if(rk[a] < rk[b])swap(a, b);
		p[b]=a;
		rk[a] = max(rk[a], rk[b]+1);
		size--;
	}
};

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<int> l(m+1), r(m+1);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		l[i] = a;
		r[i] = b;
	}
	int ans = 0;
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		a = ((a-1+ans)%m)+ 1;
		b = ((b-1+ans)%m) + 1;
		if (a > b) swap(a, b);
		DSU dsu;
		dsu.init(n);
		for (int i = a; i <= b; ++i) {
			dsu.uni(l[i], r[i]);
		}
		ans = dsu.size;
		cout << ans << endl;
	}


	return 0;
}
