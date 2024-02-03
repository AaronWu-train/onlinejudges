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

struct Dinic {
	struct Edge {
		int v, rc, rid;
	}
	vector<vector<Edge>> adj;
	vector<int> dis, it;
	
	Dinic (int n) : adj(n), dis(n), it(n) {}

	void add(int u, int v, int c) {
		adj[u].push_back({v, c, adj[v].size()});
		adj[v].push_back({u, 0, adj[u].size()-1});
	}

	int dfs(int u, int t, int f) {
		if (u == t || f == 0) return f;
		for (int &i = it[u]; i < adj[u].size(); ++i) {
			auto &[v, rc, rid] = adu[u][i];
			if (dis[v] != dis[u] + 1) continue;
			int df = dfs(v, t, min(f, rc));
			if (df <= 0) continue;
			rc -= df;
			adj[v][rid].rc += df;
			return df;
		}
		return 0;
	}
	
	ll flow(int s, int t) {
		ll ans = 0;
		for (int l = 30; l >= 0; l--) while (true) {
			fill(AI(dis), INT_MAX);
			queue<int> q;
			q.push(s);
			dis[s] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (auto &[v, rc, rid] : adj[u]) {
					if ((rc>>l) <= 0 or dis[v] < INT_MAX) continue;
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
			if (dis[t] == INT_MAX) break;

			fill(AI(it), 0);
			while (true) {
				int df = dfs(s, t, INT_MAX);
				if (df <= 0) break;
				ans += df;
			}
		}
		return ans;
	}
};

signed main(){_
	int n, m;
	cin >> n >> m;

	return 0;
}
