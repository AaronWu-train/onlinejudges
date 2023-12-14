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
int n, m;
vector<vector<int>> adj;
vector<int> scc, dfn, low;
int dfncnt = 0, cccnt=0;
stack<int> s;


void dfs(int i) {
	debug(i);
	dfncnt++;
	dfn[i] = low[i] = dfncnt;
	s.push(i);
	for (auto &j : adj[i]) {
		if (!scc[j]) {
			if (dfn[j]) {
				low[i] = min(low[i], dfn[j]);
			} else {
				dfs(j);
				low[i] = min(low[i], low[j]);
			}
		}
	}
	if (dfn[i] == low[i]) {
		cccnt++;
		while (s.top() != i) {
			scc[s.top()] = cccnt;
			s.pop();
		}
		scc[i] = cccnt;
		s.pop();
	}
}

signed main(){_
	cin >> n >> m;
	adj.resize(n+5);
	for (int i=0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}	
	scc.resize(n+5);
	dfn.resize(n+5);
	low.resize(n+5);
	for (int i = 1; i <= n; ++i){
		if (!dfn[i]) dfs(i);
	}
	cout << cccnt << endl;
	for (int i = 1; i <= n; ++i) {
		cout << scc[i] << " ";
	}
	cout << endl;
	return 0;
}
