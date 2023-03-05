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

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+5];
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> visited(n+5);

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			queue<int> bfs;
			bfs.push(i);
			visited[i] = 1;
			while(!bfs.empty()){
				int c = bfs.front();
				bfs.pop();
				for (auto &j : adj[c]) {
					if (!visited[j]) {
						visited[j] = ((visited[c]==1)? 2 : 1);
						bfs.push(j);
					}
					else if (visited[j] == visited[c]){
						cout << "IMPOSSIBLE" << endl;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << visited[i] << " \n"[i==n];
	}

	return 0;
}
