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
const int INF = 1e17;
const int NINF = -1e17;

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n+5];
	for (int i = 0; i < m; ++i) {
		int a, b, x;
		cin >> a >> b >> x;
		adj[a].pb({b, -x});
	}

	vector<int> dis(n+5, INF);
	dis[1] = 0;
	for (int t = 0; t < n; ++t) {
		for (int i = 1; i <= n; ++i) {
			for (auto [j, w] : adj[i]) {
				if (dis[i] == INF) continue;
				if (dis[i] + w < dis[j]) dis[j] = dis[i] + w; 
				dis[i] = max(dis[i], NINF);
			}
		}
	}
	
	for (int t=0; t < n; ++t) {
		for (int i = 1; i <= n; ++i) {
			for (auto [j, w] : adj[i]) {
				if (dis[i] == INF) continue;
				dis[i] = max(dis[i], NINF);
				if (dis[i] + w < dis[j]) {
					dis[j] = NINF;
				}
			}
		}
	}

	if (dis[n] == NINF) cout << -1 << endl;
	else cout << -dis[n] << endl;
	return 0;
}
