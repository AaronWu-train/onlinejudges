#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FF first
#define SS second
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
	int arr[m][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[j][i];
		}
	}
	int x, y;
	cin >> x >> y;
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, -1, 1, 0};
	queue<pair<int, int>> bfs;
	bfs.push({x, y});
	bool visited[1505][1505] = {0};
	visited[x][y] = 1;
	while (!bfs.empty()) {
		auto cur = bfs.front();
		bfs.pop();
	//	debug(cur.FF, cur.SS);
		for (int i = 0; i < 4; ++i) {
			if (cur.FF + dx[i] >= 0 && cur.FF + dx[i] < m &&
					cur.SS + dy[i] >= 0 && cur.SS + dy[i] < n &&
					!visited[cur.FF + dx[i]][cur.SS + dy[i]] && 
					arr[cur.FF][cur.SS] <= arr[cur.FF + dx[i]][cur.SS + dy[i]]) {
				visited[cur.FF + dx[i]][cur.SS + dy[i]] = 1;
				bfs.push({cur.FF + dx[i], cur.SS + dy[i]});
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j]) {
				printf("(%d,%d)\n", i, j);
			}
		}
	}

	return 0;
}
