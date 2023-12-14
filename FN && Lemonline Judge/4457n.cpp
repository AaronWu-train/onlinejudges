#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
#define pll pair<ll, ll>
const int mod = 998244353;


signed main(){_
	
	int n, m;
	cin >> n >> m;
	vector<vector<pll>> adj(n+1);

	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ll a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, w});
	}
	for (int s = 1; s <= n; ++s) {
		vector<ll> dis(n+1, LLONG_MAX);
		dis[s] = 0;
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push({0, s});
		vector<bool> visited(n+1, 0);

		while (!pq.empty()){
			auto [ww, v] = pq.top();
			pq.pop();
			if(visited[v]) continue;
			visited[v] = 1;
			for (auto [u, w] : adj[v]) {
				if (dis[v] + w < dis[u]) {
					dis[u] = dis[v] + w;
					pq.push({dis[u], u});
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dis[i] == LLONG_MAX) ans = (ans + mod - 1)%mod;
		    else	ans = (ans + dis[i] % mod) % mod; 
		}
	}
	cout << ans%mod << endl;

	return 0;
}
