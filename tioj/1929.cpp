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

vector<int> kosaraju (vector<vector<int>> & graph, int& sccsize) {
	vector<int> visited(graph.size());
	vector<int> scc(graph.size());
	vector<int> outorder;
	
	function <void(int)> dfs = [&] (int u) {
		if (visited[u]) return;
		for (auto &v : graph[u]) {
			dfs(v);
		}
		outorder.pb(u);
	};	

	for (int i = 0; i < graph.size(); ++i) dfs(i);


	vector<vector<int>> readj(graph.size());
	for (int i = 0; i < graph.size(); ++i) {
		for (auto &j : graph[i]) readj[j].pb(i);
	}

	std::reverse(AI(outorder));
	
	int sccid = 0;
	
	function<void(int)> sfd = [&](int u) {
		scc[u] = sccid;

		for (auto &v : readj[u]) {
			if (scc[v]) continue;
			sfd(v);
		}
	};

	for (auto &u : outorder) if (!scc[u]) { sccid++; sfd(u);}
	sccsize = sccid;
	return scc;
}




signed main(){_
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}	
	int sccsize = 0;
	vector<int> scc = kosaraju(adj, sccsize);
	vector<vector<int>> sccgraph(sccsize + 1);
	vector<int> incnt(sccsize+1);

	for (int i = 1; i <= n; ++i) {
		for (auto &j : adj[i]) {
			if (scc[i] != scc[j]) {
				sccgraph[scc[i]].pb(scc[j]);
				incnt[scc[j]]++;
			}
		}
	}
	
	int s = 1;
	for (int i = 1; i <= sccsize; ++i) {
		if(incnt[i] == 0) {s = i; break;}
	}
	
	vector<int> dep(sccsize+5);
	queue<int> bfs;
	bfs.push(s);
	dep[s] = 1;
	vector<bool> visited(n+5);
	int mxdep = 1;
	while (bfs.size()){ 
		int i = bfs.front();
		bfs.pop();
		for (auto j : sccgraph[i]) {
			if (visited[j]) continue;
			dep[j] = dep[i] + 1;
			mxdep=max(mxdep, dep[j]);	
			visited[j] = 1;
			bfs.push(j);
		}
	}
	cout << mxdep << endl;
	for (int i = 1; i <= n; ++i) {
		cout << dep[scc[i]] << " ";
	}
	cout << endl;

	return 0;
}
