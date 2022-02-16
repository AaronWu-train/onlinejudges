#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n,m,q;
    cin >> n >> m;
    int graph[505][505] = {0};
    bitset<505>used[505];
    for (int i = 1; i <= n; ++i) {
        used[i][0] = 1;
        used[i][m+1] = 1;
        for (int j = 1; j <= m; ++j) {
            cin >> graph[i][j];
        }
    }
    for (int j = 0; j <= m+1; ++j) {
        used[0][j] = 1;
        used[n+1][j] = 1;
    }
    
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        ll ans = graph[x][y];
        used[x][y] = 1;
        int k;
        k = 1;
        while (!used[x][y+k]) {//up
            ans+=graph[x][y+k];
            used[x][y+k] = 1;
            k++;
        }
        
        k = 1;
        while (!used[x+k][y]) {//right
            ans+=graph[x+k][y];
            used[x+k][y] = 1;
            k++;
        }
        
        k = 1;
        while (!used[x-k][y]) {//left
            ans+=graph[x-k][y];
            used[x-k][y] = 1;
            k++;
        }
        k = 1;
        while (!used[x][y-k]) {//down
            ans+=graph[x][y-k];
            used[x][y-k] = 1;
            k++;
        }
        cout << ans << endl;
    }
    
    
    
    return 0;
}
