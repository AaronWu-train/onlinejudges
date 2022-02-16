#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <queue>
#include <utility>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

bitset<260>arr[260];
bitset<260>visited[260];
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
int main() {_
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool eee;
            cin >> eee;  arr[i][j] = eee;
        }
    }
    queue <pair<int, int>> bfs;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int l = i;
            int r = i;
            int up = j;
            int dn = j;
            int area = 0;
            if (!visited[i][j]&&arr[i][j]) {
                //bfs
                visited[i][j] = true;
                bfs.push(make_pair(i, j));
                while (bfs.size()!=0) {
                    area++;
                    auto cur = bfs.front();
                    bfs.pop();
                    dn = max(dn, cur.first);
                    up = min(up, cur.first);
                    r = max(r, cur.second);
                    l = min(l, cur.second);
                    for (int k = 0; k < 4; k++) {
                        if (arr[cur.first+y[k]][cur.second+x[k]] && !visited[cur.first+y[k]][cur.second+x[k]]) {
                            visited[cur.first+y[k]][cur.second+x[k]] = true;
                            bfs.push(make_pair(cur.first+y[k],cur.second+x[k]));
                        }
                    }//TODO:更新
                }
                //TODO:記得轉0base
                cout << l-1 << " " << up-1 << " " << r-1 << " " << dn-1 << " " << area <<endl;
            }
            
        }
    }
    
    return 0;
}
