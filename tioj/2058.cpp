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
const ll INF = 1e18;

signed main(){_
	int t;
	cin >> t;
	while (t--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<pair<ll, ll>> adj[n];
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].pb({b,w});
		}
		vector<ll> dis(n, INF);
		vector<ll> rdis(n, INF);
		dis[s] = 0;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
		pq.push({0ll, s});
		while(!pq.empty()) {
			auto [w, v] = pq.top();
			pq.pop();
			if (rdis[v] < w) continue;
			for (auto &[i, w2] : adj[v]) {
				ll dt = w + w2;
				if (dt < dis[i]) {
					swap(dis[i], dt);
					pq.push({dis[i], i});
				}
				if (dt < rdis[i] && dt != dis[i]) {
					swap(dt, rdis[i]);
					pq.push({rdis[i], i});
				}
			}
		}
		cout << rdis[t] - dis[t] << endl;
	}

	return 0;
}
