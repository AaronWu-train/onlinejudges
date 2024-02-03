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

struct MCMF {
	struct E {int v, c; ll k; int r, rc; };
	vector<vector<E>> adj;
	vector<int> par, par_eid;
	MCMF(int n): adj(n), par(n), par_eid(n) { }
	void add(int u, int v, int c, ll k) {
		adj[u].pb({v,c,k,(int)adj[v].size(),c});
		adj[v].pb({u,0,-k,(int)adj[u].size()-1,0});
	}
	ll spfa(int s, int t) {
		fill(AI(par), -1);
		vector<ll> dis(par.size(), LLONG_MAX);
		vector<bool>in_q(par.size(), 0);
		queue <int> q;
		dis[s] = 0; q.push(s); in_q[s] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop(); in_q[u] = 0;
			for (int i = 0; i < (int)adj[u].size(); ++i) {
				auto &[v,c,k,r,rc] = adj[u][i];
				if (rc > 0 and dis[u] + k < dis[v]) {
					dis[v] = dis[u] + k;
					par[v] = u;
					par_eid[v] = i;
					if (!in_q[v]) q.push(v);
					in_q[v] = 1;
				}
			}
		}
		return dis[t];
	}
	pair<int, ll> flow(int s, int t) {
		int flow = 0;
		ll cost = 0, d;
		while((d = spfa(s, t)) < LLONG_MAX) {
			int cur = INT_MAX;
			for (int u = t; u != s; u = par[u]) {
				cur = min(cur, adj[par[u]][par_eid[u]].rc);
			}
			flow += cur; cost += d * cur;
			for (int u = t; u != s; u = par[u]) {
				adj[par[u]][par_eid[u]].rc -= cur;
				adj[u][ adj[par[u]][par_eid[u]].r].rc += cur;
			}
		}	
		return make_pair(flow, cost);
	}
};


signed main(){_
	ll n, m, a, c;
	cin >> n >> m >> a >> c;
	MCMF ff( 2*n + 5);
	int t = 2*n + 1;
	for (int i = 1; i <= n; ++i) {
		ff.add(0, i, m, 0);
		ff.add(0, i, 1e6, c);
		int d; cin >> d;
		ff.add(i, i + n, d, 0);
		ff.add(i+n, t, 1e6, 0);
	}
	for (int i = 1; i < n; ++i) {
		ff.add(i, i+1, 1e6, a);
	}	
	auto [flow, cost] = ff.flow(0, t);
	cout << cost << endl;
	vector<int> ans(n+5);
	for (auto &i : ff.adj[0]) {
		ans[i.v] += i.c - i.rc;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
	
	return 0;
}
