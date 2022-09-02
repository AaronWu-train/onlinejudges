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
int n, q;

struct Tree{
    int n;
    vector<ll>dp;
    vector<map<int, ll>>child;
    vector<int>fa;

    ll dfs(int i) {
        for (auto [j, w] : child[i]) {
            dp[i] += w + w;
            dp[i] += dfs(j);
        }
        return dp[i];
    }
    
    void init(int _n) {
        n = _n;
        dp.resize(n+5,0);
        child.resize(n+5);
        fa.resize(n+5,0);
        for (int i = 0; i < n-1; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            child[a].insert({b, w});
            fa[b] = a;
        }
        dfs(0);
        debug(fa[0]);
    }
    
    void modify(int d, int m) {
        ll dis = child[fa[d]][d];
        int k = m - dis;
        while (fa[d] != d) {
            dp[fa[d]] += 2 * k;
            d = fa[d];
        }
    }
    
}tree;

signed main() {_
    cin >> n >> q;
    tree.init(n);
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (!tp) {
            int d, m;
            cin >> d >> m;
            tree.modify(d, m);
        }else{
            int k;
            cin >> k;
            cout << tree.dp[k] << endl;
        }
    }
    return 0;
}
