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
#define int long long
#define pii pair<ll, ll>
#define first FF
#define second SS

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<pii> adj[n+1];
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, w});
	}
	
	vector<bool> visited(n+1);
	vector<int> dis(n+1, LLONG_MAX);
	dis[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
   	pq.push({0, 1});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		for (auto &[v, w] : adj[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}	
	for (int i = 1; i <= n; ++i){ 
		cout << dis[i] << " ";
	}



	return 0;
}
