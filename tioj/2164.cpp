#pragma GCC optimize("Ofast")
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


    
    int fa[maxn] = {0};
    
    inline void init(int n) {
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
        }
    }
    inline int query(int x) {
        if (fa[x] == x) return x;
        fa[x] = query(fa[x]);
        return fa[x];
    }
    inline void modify(int x, int y) {
        int a = query(x);
        int b = query(y);
        fa[a] = b;
    }


signed main() {_
    int n;
    cin >> n;
    ll x[n], y[n], z[n];
   
    init(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    vector<pair<ll, pair<int, int>>> sides(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            sides[n*i+j] = {(x[i] - x[j]) * (x[i] - x[j])
                + (y[i] - y[j]) * (y[i] - y[j])
                + (z[i] - z[j]) * (z[i] - z[j]), {i,j}};
        }
    }
    sort(AI(sides), [](auto& a, auto& b) {
        return a.first < b.first;
    });
    
    ll ans = 0;
    for (auto &i : sides) {
        if (query(i.second.first) != query(i.second.second)) {
            ans += i.first;
            modify(i.second.first, i.second.second);
        }
    }
    cout << ans << endl;
    
    return 0;
}
