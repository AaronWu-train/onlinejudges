#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
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
const int mod = 998244353;

signed main() {_
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dis(n+5, vector<ll>(n+5, 998244352));
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min((dis[i][k] + dis[k][j]), dis[i][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = (ans + dis[i][j]) % mod;
        }
    }
    cout << ans << endl;
    
    return 0;
}
