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
const int maxn = 5005;

signed main() {_
    int n;
    cin >> n;
    ll x[n], y[n], z[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<ll>dis(n+5, LLONG_MAX);
    dis[0] = 0;
    bool in_mst[maxn] = {0};
    ll parent[maxn] = {0};
    ll ans = 0;
    
    
    for (int i = 0; i < n; ++i) {
        int id = n;
        for (int j = 0; j < n; ++j) {
            if (!in_mst[j] && dis[j] <= dis[id]) id = j;
        }
        
        in_mst[id] = 1;
        ll k = parent[id];
        ans += (x[id] - x[k]) * (x[id] - x[k])
        + (y[id] - y[k]) * (y[id] - y[k])
        + (z[id] - z[k]) * (z[id] - z[k]);
        
        for (int j = 0; j < n; ++j) {
            if (id == j) continue;
            ll t = (x[id] - x[j]) * (x[id] - x[j])
            + (y[id] - y[j]) * (y[id] - y[j])
            + (z[id] - z[j]) * (z[id] - z[j]);
            if (t <= dis[j]) {
                dis[j] = t;
                parent[j] = id;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
