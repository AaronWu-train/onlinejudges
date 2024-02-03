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

struct Dinic {
	struct E { int v, c, r, rc; };
	vector<vector<E>> adj;
	vector<int> vis, dis, it;
	Dinic (int n) : adj(n), vis(n), dis(n), it(n) {}
	void add(int u, int v, int c, int d) {
		adj[u].pb({v, c, (int) adj[v].size(), c});
		adj[v].pb({u, d, (int) adj[v].size() - 1, d});
	}
	bool bfs(int s, int t) {
		fill(AI(dis), INT_MAX); 
		queue<int> q;
		q.push(s); dis[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto& [v, c, r, rc]: adj[u]) {
				if (dis[v] < INT_MAX or rc == 0) continue;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		return dis[t] < INT_MAX;
	}
	int dfs(int u, int t, int cap) {
		if (u == t or cap == 0) return cap;
		vis[u] = 1;
		for (int &i = it[u]; i < (int) adj[u].size(); ++i) {
			auto &[v, c, r, rc] = adj[u][i];
			if (dis[u] + 1 != dis[v]) continue;
			int tmp = dfs(v, t, min(cap, rc));
			if (tmp > 0) {
				rc -= tmp;
				adj[v][r].rc += tmp;
				return tmp;
			}
		}
		return 0;
	}
	ll flow(int s, int t) {
		ll ans = 0, tmp;
		while(bfs(s, t)) {
			fill(AI(vis), 0);
			fill(AI(it), 0);
			while ((tmp = dfs(s, t, INT_MAX)) > 0) {
				ans += tmp;
			}
		}
		return ans;
	}
	bool inSCut(int u) {return dis[u] < INT_MAX; };
};

signed main(){_
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int,int,int>> edg;
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ll a, b, c; 
		cin >> a >> b >> c;
		ans += c;
		edg.pb(make_tuple(a, b, c));
	}	

	while (q--) {
		int s, t;
	   	cin >> s >> t;
		Dinic d(n+5);
		for (auto &[u, v, c] : edg) {
			d.add(u, v, c, c);
		}
		
		cout << ans - d.flow(s, t) << endl;
	}
	
	return 0;
}
