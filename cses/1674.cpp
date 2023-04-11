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

const int maxn = 2e5+5;
vector<int> adj[maxn];
int sz[maxn];

int dfs(int i, int fa) {
	sz[i] = 1;
	for (auto &v : adj[i]) {
		if (v == fa) continue;
		sz[i] += dfs(v, i);
	}	
	return sz[i];
}

signed main(){_
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int boss;
	   	cin >> boss;
		adj[i].pb(boss);
		adj[boss].pb(i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) cout << sz[i]-1 << " ";
	cout << endl;

	return 0;
}
