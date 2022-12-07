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

void dfs(string i, int dp, map<string, int> &dep, map<string, vector<string>>& adj, map<string, bool> &visited) {
	visited[i] = 1;
	dep[i] = dp;
	for (auto &j : adj[i]) {
		if (!visited[j]) {
			dfs(j, dp+1, dep, adj, visited);
		}
	}
}


signed main(){_
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, vector<string>> adj;
		string a, b;
		while (cin >> a >> b && (a != "%" && b != "%") ) {
			adj[a].pb(b);
			adj[b].pb(a);
		}
		map<string, int> dep;

	}

	return 0;
}
