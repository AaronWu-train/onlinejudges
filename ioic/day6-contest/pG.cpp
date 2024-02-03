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

const int mxn = 2e5+5;
vector<int> adj[mxn];
int dep[mxn], low[mxn], vis[mxn];

bool dfs(int i, int fa) {
	dep[i] = low[i] = dep[fa]+1;
	int cnt = 0;
	bool ret = 1;	
	for (auto &j : adj[i]) {
		if (j == fa) continue;
		if (!dep[j]) {
			ret = ret && dfs(j, i);
			low[i] = min(low[i], low[j]);
			if (low[j] < dep[i]) {
				debug(i, j, dep[j], low[j], cnt, "RR");
				cnt++;
			}
		} else if (dep[j] < dep[i]) {
			cnt++;
			debug(i, j, dep[j], low[j], cnt, "TT");
			low[i] = min(low[i], dep[j]);
		}
	}
	debug(i, low[i], dep[i], ret, cnt);
	return ret && (cnt <= 1);
}


signed main(){_
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	auto ret = dfs(1, 1);
	if (ret) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
