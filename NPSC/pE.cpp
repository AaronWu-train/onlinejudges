#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
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
	int n;
	cin >> n;
	vector<int> last(n/2 + 5, 0);
	int curh = 0;
	vector<int> adj[n+5];
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		curh += k;
		if (k < 0) {
			int l = last[curh+1];
			adj[l].pb(i);
			adj[i].pb(l);
		} else {
			last[curh] = i;
		}
	}

	for (int i = 1; i < n; ++i) {
		adj[i].pb(i+1);
		adj[i+1].pb(i);
	}
	int q;
	cin >> q;
	while(q--) {
		int s, t;
		cin >> s >> t;
		queue<pii> bfs;
		vector<bool>visited(n+1);
		bfs.push({s, 0});
		visited[s] = 1;
		while(!bfs.empty()) {
			auto [cur, dis] = bfs.front();
			bfs.pop();
			if (cur == t) {
				cout << dis << endl;
				break;
			}
			for (auto &j : adj[cur]){
				if (!visited[j]) {
					bfs.push({j, dis+1});
					visited[j] = 1;
				}
			}
		}	
	}
	

	return 0;
}
