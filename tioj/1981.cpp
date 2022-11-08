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
bool visited[maxn];
int sccsz[maxn];
int sccid[maxn];
int low[maxn], dfn[maxn];
stack<int> sccstk;
int sccind, dfnind;

void dfs(int x, int fa) {
	sccstk.push(x);
	low[x] = dfn[x] = ++dfnind;

	for (auto &i : adj[x]) {
		if (i == fa) continue;
		if (visited[i]) low[x] = min(low[x], dfn[i]);
		else {
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		}
	}
	int tp;	
	if (low[x] == dfn[x]) {
		do{
			tp = sccstk.top();
			sccstk.pop();
			sccid[tp] = sccind;
			sccsz[sccind]++;
		} while(tp != x);
		++sccind;
	}
}

int f(int x, vector<vector<int>>&nadj, vector<bool> &vs2) {
	vs2[x] = 1;
	int ret = 0;
	for (auto &j : nadj[x]) {
		if (!vs2[j]) ret = max(ret, f(j, nadj, vs2));
	}
	ret += sccsz[x];

	return ret;
}


signed main(){_
	int n, m;
	while(cin >> n >> m){
	for (int i = 0; i < maxn; ++i) {
		visited[i] = sccid[i] = low[i] = dfn[i] = sccsz[i] = 0;
		adj[i].clear();
		sccind = dfnind = 0;
	}
	sccstk= stack<int>();
	for (int i = 0; i < m; ++i ) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}	
	for(int i = 0; i < n; ++i) {
		if (!visited[i]) dfs(i, i);
	}
	vector<vector<int>> nadj(sccind+5);
	vector<int> indeg(sccind+5);
	for(int i = 0; i < n; ++i) {
		for (auto &j : adj[i]) {
			if (sccid[i] != sccid[j]){
				nadj[sccid[j]].pb(sccid[i]);
				indeg[sccid[i]]++;
			}
		}	
	}
	int ans = 0;
	vector<int> dp(sccind+5, 0);
	queue<int> bfs;
	for (int i = 0; i < sccind; ++i) {
		vector<bool>vs2(sccind+5);
		if (indeg[i] == 0) ans = max(ans,f(i, nadj, vs2) );	
	}
	cout << ans << endl;
	}
	return 0;
}
