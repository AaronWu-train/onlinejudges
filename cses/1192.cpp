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

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int n, m;
void dfs(int i, int j, vector<string>& mp, vector<vector<bool>>& visited) {
	debug("TT", i, j);
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		if (0 <= i + dx[k] && i + dx[k] < n && 0 <= j + dy[k] && j + dy[k] < m) {
			if (mp[i + dx[k]][j + dy[k]] == '.') {
				dfs(i + dx[k], j + dy[k], mp, visited);
			}
		}
	}
}


signed main(){_
	cin >> n >> m;
	vector<string> mp(n);
	for (auto &i : mp) cin >> i;
	vector<vector<bool>> visited(n,vector<bool>(m, 0));

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == '.' && visited[i][j] == 0) {
				ans++;
				debug(i, j);
				dfs(i, j, mp, visited);
			}	
		}
	}
	cout << ans << endl;

	return 0;
}
