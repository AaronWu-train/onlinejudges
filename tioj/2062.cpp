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
const int maxn = 1e6+5;
vector<int> adj[maxn];
signed main(){_
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	int color[maxn] = {0};
	bool flag = 1;
	queue<int>bfs;
	map<int, int> mp;

	for (int i = 1; i <= n; ++i) {
		if (color[i]) continue;
		color[i] = 1;
		bfs.push(i);
		while (!bfs.empty()) {
			int c = bfs.front();
			bfs.pop();
			mp[color[c]]++;
			debug(c, color[c], mp[color[c]]);
			for (auto j : adj[c]) {
				if (color[j]) {
					if (color[j] == color[c]) {
						flag = 0;
						break;
					}
				} else {
					color[j] = -color[c];
					bfs.push(j);
				}
			}
			if (!flag) break;
		} 
		if (!flag) break;
	}

	if (!flag) cout << -1 << endl;
	else {
		cout << mp[1] << " " << mp[-1] << endl;
		for (int i = 1; i <= n; ++i) {
			if (color[i] == 1) cout << i << " ";
		}
		cout << endl;
		for (int i = 1; i <= n; ++i) {
			if (color[i] == -1) cout << i << " ";
		}

	}

	return 0;
}
