#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define AI(x) begin(x),end(x)
#ifdef AaW 
#define debug(args...) LKJ("\033[32m[ " + string(#args) + " ]\033[0m", args)
template <class I> void LKJ(I && x) { cerr << x << endl;}
template <class I, class ...T> void LKJ(I&&x, T&&...t){ cerr << x << ", "; LKJ(t...);}
template <class I> void OI(I a, I b) {while(a != b){cerr << *a << " ", a++;}cerr<<endl;}
#else 
#define OI(...) 0
#define debug(...) 0
#endif
#define _ ios::sync_with_stdio(0); cin.tie(0);

bool dfs(int i, vector<int>&match, vector<int>&vis, vector<vector<int>> &adj) {
	vis[i] = 1;
	for (auto j : adj[i]) {
		if (match[j] == -1 || (!vis[match[j]] && dfs(match[j], match, vis, adj))) {
			match[j] = i;
			return 1;
		}	
	}
	return 0;
}

void dfs2(int i, vector<int>& vis2, vector<vector<int>>&adj) {
	vis2[i] = 1;
	for (auto &j : adj[i]) {
		if (!vis2[j]) dfs2(j, vis2, adj);
	}
}

signed main() {_
	int n, k; 
	cin >> n >> k;
	vector<vector<int>> adj(k+1);
	for (int i = 0; i < n; ++i) {
		int a,b; cin >> a >> b;
		adj[a].pb(b);
	}
	vector<int>match(k + 1, -1);
	vector<int> vis(k + 1, 0);
	for (int i = 1; i <= k; ++i) {
		fill(AI(vis), 0);
		dfs(i, match, vis, adj);
	}

	vector<bool> has(k+1);
	vector<vector<int>> adj2(2*k+3);
	for (int i = 1; i <= k; ++i) {
		for (auto &j : adj[i]) {
			if (match[j] == i) {
				has[i] = 1;
				adj2[j+k].pb(i);
			}
			else {
				adj2[i].pb(j+k);
			}
		}	
	}

	vector<int> vis2(2*k+3, 0) ;
	vector<int> al, ar;
	for (int i = 1; i <= k; ++i) {
		if (!has[i]&&!vis2[i]) dfs2(i, vis2, adj2);
	}
	for (int i = 1; i <= k; ++i) {
		if (!vis2[i]) al.pb(i);
		if (vis2[i+k])ar.pb(i);
	}
	cout << al.size() << " " << ar.size() << endl;
	for (auto &i : al) cout << i << " "; cout << endl;
	for (auto &i : ar) cout << i << " "; cout << endl;

	return 0;
}
