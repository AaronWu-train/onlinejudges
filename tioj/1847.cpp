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

int main(){_
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	vector<int>adj[n+5];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int d;
	cin >> d;

	queue<pair<int, int>> bfs;
	vector<bool> visited(n+5, 0);
	ll ans = 0;
	bfs.push({0, 0});
	visited[0] = 1;
	while(!bfs.empty()) {
		auto [cur, dis] = bfs.front();
		bfs.pop();
		ans += arr[cur];
		if (dis < d) {
			for (auto k : adj[cur]) {
				if(!visited[k]) {
					bfs.push({k, dis+1});
					visited[k] = 1;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
