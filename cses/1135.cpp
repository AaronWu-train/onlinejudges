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

int fa[(int)2e5+5][22];
vector<int>child[(int)2e5+5];
int dep[(int)2e5+5];

void dfs(int i) {
	for (int j = 1; j <= 20; ++j) {
		fa[i][j] = fa[fa[i][j-1]][j-1];
	}
	for (auto j : child[i]) {
		dep[j] = dep[i]+1;
		dfs(j);
	}
}

int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	for (int i = 1, k = 0; i <= dep[b] - dep[a]; i<<=1, k++) {
		if (i & (dep[b] - dep[a])) b = fa[b][k];
	}	
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}

void dfshh(int i, vector<vector<int>> & adj) {
	for (auto &j : adj[i]) {
		if (j == fa[i][0]) continue;
		fa[j][0] = i;
		child[i].push_back(j);
		dfshh(j, adj);
	}
}


int main(){_
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfshh(1, adj);
	for (int j = 0; j <= 20; ++j) {
		fa[1][j] = 1;
	}
	dep[1] = 0;
	dfs(1);
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a>> b;
		int k = lca(a, b);
		cout << dep[a] - dep[k] + dep[b] - dep[k]<< endl;
	}

	return 0;
}
