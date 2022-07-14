#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
vector<int> adj[1005];
int n, k;

int dfs(int x, int deep, vector<bool>&visited, vector<int>& node) {
	int ans = 0;

	if (deep == k) return node[x];
	visited[x] = 1;
	for (auto i : adj[x]) {
		if (!visited[i]) {
			ans = max(ans, dfs(i,deep+1,visited,node ));
		}
	}
	return ans+node[x];
}

int main(){_
	cin >> n >> k;
	vector<int> node(n+5,0);
	for (int i = 1; i <= n; ++i) {
		cin >> node[i];
	}
	for(int i = 0; i < n-1; ++i) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n+5,0);
	cout << dfs(1,0,visited,node)<< endl;

	return 0;
}
