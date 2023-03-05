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

vector<int> ans;
vector<vector<int>> adj;

void dfs(int i, int fa, vector<int> &p) {
	debug(i);
	for (auto &j : adj[i]){
		if (j == fa) continue;
		if (p[j]) {
			vector<int> ans;
			ans.pb(i);
			while(ans.back() != j) {
				ans.pb(p[ans.back()]);
			}	
			ans.pb(i);
			cout << ans.size() << endl;
			for (auto &k : ans) cout << k << " \n"[&k == &ans.back()];
			exit(0);
		}
		p[j] = i;
		dfs(j, i, p);
	}	
}


signed main(){_
	int n, m;
	cin >> n >> m;
	adj.resize(n + 5);
	for (int i = 0 ; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> p(n+5);
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			p[i] = i;
			dfs(i, 0, p);
		}	
	}
	cout << "IMPOSSIBLE\n";	




	return 0;
}
