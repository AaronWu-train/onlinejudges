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
#define pii pair<ll, ll>
#define FF first
#define SS second
#define int long long
const int mod = 1e9 + 7;

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj(n+1);
	vector<int> indeg(n+1);
	for (int i = 0; i < m; ++i){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		indeg[v]++;
	}



	queue<int> q;
	for (int i = 1; i <= n; ++i) if (indeg[i] == 0) q.push(i);

	vector<vector<pii>> dp(n+1, vector<pii>(n+1, make_pair(-1e9-5, 0)));
	for (int i = 2; i <= n; ++i){
		dp[1][i] = {0, 1};
	}
	dp[1][1] = {-1e9-5, 0};
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			dp[i][u] = max(dp[i][u], {-1e9-5, 0});
		}
		dp[u][u] = {-1e9-5, 0};
		for (auto &[v, w] : adj[u]) {
			for (int i = 1; i <= n; ++i) {
				if (i == u || dp[u][i].FF < 0) continue;
				if (dp[v][i].FF < dp[u][i].FF + w) dp[v][i] = dp[u][i], dp[v][i].FF+=w;
				else if (dp[v][i].FF == dp[u][i].FF+w) dp[v][i].SS = (dp[v][i].SS + dp[u][i].SS)%mod;
			}	
			indeg[v]--;
			if (indeg[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (dp[n][i].FF < 0) cout << -1 << endl;
		else cout << dp[n][i].FF << " " << dp[n][i].SS << endl;
	}


	return 0;
}
