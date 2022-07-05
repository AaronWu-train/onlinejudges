#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int INF = 1e9+7;
signed main() {_
    int n,m;
    cin >> n >> m;
    while (n&m) {
        vector<vector<int>> adj(n+5,vector<int>(n+5,INF));
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a][b] = 1;
        }
        int ans = INF;
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    adj[i][j] = min( adj[i][j], adj[i][k]+adj[k][j] );
                    if (i==j)ans = min(ans,adj[i][j]);
                }
            }
        }
        cout << ((ans==INF)?0:ans) << endl;
        cin >> n >> m;
    }
    return 0;
}
