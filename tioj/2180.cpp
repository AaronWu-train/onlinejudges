#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define pii pair<int, int>
#define AI(x) begin(x),end(x)
#ifdef AaW 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mat[1005][1005];
int INF = 1e9+7;
int r, c, n, rs, cs, rd, cd;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool check(int x) {
	queue<pii> bfs;
	vector< vector<bool> > visited(1005, vector<bool>(1005, 0));
	bfs.push({rs, cs});
	visited[rs][cs] = 1;
	while(!bfs.empty()) {
		auto cur = bfs.front();
		bfs.pop();
		for (int j = 0; j < 4; ++j) {
			if (cur.first+dx[j] >= 0 && cur.second+dy[j] >= 0 &&
					!visited[cur.first+dx[j]][cur.second+dy[j]] && 
					mat[cur.first+dx[j]][cur.second+dy[j]] <= x){
				visited[cur.first+dx[j]][cur.second+dy[j]] = 1;
				bfs.push({cur.first+dx[j], cur.second+dy[j]});
			}
		}
	}
	return visited[rd][cd];
}

signed main(){_
	for (auto &i : mat) for (auto &j : i) j = INF;
	cin >> r >> c;
	cin >> rs >> cs >> rd >> cd;
	cin >> n;
	mat[rs][cs] = mat[rd][cd] = 0;
	for (int i = 0; i < n; ++i) {
		int x, y, l;
		cin >> x >> y >> l;
		mat[x][y] = l;
	}
	ll l = 0, r = 1e9+5;
	while (l < r) {
		ll mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;

	return 0;
}
