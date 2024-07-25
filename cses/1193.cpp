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
vector<char> ds = {'D', 'U', 'R', 'L'};

int n, m;

signed main(){_
	cin >> n >> m;
	int ax, ay, bx, by;
	vector<string> mp(n);
	for (auto &i : mp) cin >> i;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'A') ax = i, ay = j;
			if (mp[i][j] == 'B') bx = i, by = j;
		}
	}
	vector<vector<bool>> visited(n,vector<bool>(m, 0));
	vector<vector<int>> dir(n,vector<int>(m));
	queue <pair<int, int>> bfs;
	visited[ax][ay] = 1;
	bfs.push(make_pair(ax, ay));
	while (!bfs.empty()) {
		auto [i, j] = bfs.front();
		bfs.pop();

		if (mp[i][j] == 'B') {
			cout << "YES\n";
			vector<char> s;
			while (!(i == ax && j == ay)){
				int k = dir[i][j];
				s.pb(ds[k]);
				i -= dx[k];
				j -= dy[k];		
			}
			cout << s.size() << endl;
			for (int k = s.size() - 1; k >= 0; --k) {
				cout << s[k];
			}
			cout << endl;
			return 0;
		}
		for (int k = 0; k < 4; ++k) {
			if (0 <= i + dx[k] && i + dx[k] < n && 0 <= j + dy[k] && j + dy[k] < m) {
				if (mp[i + dx[k]][j + dy[k]] != '#' && visited[i + dx[k]][j + dy[k]] == 0) {
					bfs.push(make_pair(i + dx[k], j + dy[k]));
					dir[i+dx[k]][j+dy[k]] = k;
					visited[i + dx[k]][j + dy[k]] = 1;
				}
			}
		}
	}
	cout << "NO" << endl;

	return 0;
}
