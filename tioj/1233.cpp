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
    int m,n;
    cin >> m >> n;
	bool visited[600][600] = {0};
    int dx[] = {-1,0,1,-1,1,-1,0,1};
    int dy[] = {-1,-1,-1,0,0,1,1,1};
    vector<string>gph(m);
	int ans = 0;
    vector<int>level = {0,1,2,4,6,10,12,14,16,18,20};
    for (int i = 0; i < m; ++i) {
        cin >> gph[i];
    }
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]&&gph[i][j]=='1') {
                queue<pair<int,int>>bfs;
               	bfs.push({i,j});
				visited[i][j] = 1;
				ans++;
				debug(i,j);
				while(!bfs.empty()) {
					auto [x,y] = bfs.front();
					debug(x,y);
					bfs.pop();
					for (int t = 0; t < 8; ++t) {
						if (x+dx[t]<m&&x+dx[t]>=0&&y+dy[t]<n&&y+dy[t]>=0&& !visited[ x+dx[ t ] ][ y+dy[ t ] ] && gph[ x+dx[ t ] ][ y+dy[ t ] ]=='1') {
							visited[x+dx[t]][y+dy[t]] = 1;
							bfs.push({ x+dx[t], y+dy[t] });
						}
					}
				}
            }
        }
    }
	cout << max(10,(int)(lower_bound(AI(level),ans) - level.begin())) << endl;


	return 0;
}
