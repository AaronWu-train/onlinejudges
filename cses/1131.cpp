#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int maxn = 2e5+5;
vector<int> adj[maxn];

void dfs(int i, vector<int> & dep, vector<bool> & visited) {
	visited[i] = 1;

	for (auto &v : adj[i]) {
		if (!visited[v]) {
			dep[v] = dep[i]+1;
			dfs(v, dep, visited);
		}
	}
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> dep(n+1, 0);
	vector<bool> visited(n+1, 0);
	dfs(1, dep, visited);
	int maxDeepNode = 1;
	for (int i = 1; i <= n; ++i) {
		if (dep[i] > dep[maxDeepNode]) maxDeepNode = i;
	}
	
	fill(dep.begin(), dep.end(), 0);
	fill(visited.begin(), visited.end(), 0);

	dfs(maxDeepNode, dep, visited);

	int diameter = 0;
	for (auto &i : dep) diameter = max(i, diameter);
	cout << diameter << endl;

	return 0;
}
