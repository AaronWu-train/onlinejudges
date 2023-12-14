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


void dfs (int i, vector<int> &fa, vector<vector<int>> & adj, vector<int> &a, vector<int>&b) {
	a[i] = 0;
	b[i] = 1;
	int k = INT_MIN;
	for (auto & j : adj[i]) {
		if (j == fa[i]) continue;
		fa[j] = i;
		dfs(j, fa, adj, a, b);

		k = max(k, b[j] - a[j]);
		a[i] += a[j];
		b[i] += a[j];
	}
	a[i] += k;
}


signed main() {_
	int n;
	cin >> n;
	if (n == 1) {cout << 0 << endl; return 0;}
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> a(n+1), fa(n+1), b(n+1);
	dfs(1, fa, adj, a, b);
	OI(AI(a));
	OI(AI(b));
	cout << a[1] << endl;
	

	return 0;
}
