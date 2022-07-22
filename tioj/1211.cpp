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
const int maxn = 10005;

struct DJS{
    int fa[maxn];
    int n;
    void init(int _n){
        n = _n;
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
        }
    }
    int query(int i) {
        if (fa[i] == i) return i;
        fa[i] = query(fa[i]);
        return fa[i];
    };
    void modify(int a, int b) {
        int k = query(a);
        int j = query(b);
        fa[k] = j;
    }
};

signed main() {_
    int n, m;
    cin >> n >> m;
    while (n||m) {
        DJS dsu;
        dsu.init(n);
        vector<pair<int, pair<int, int>>> side;
        for (int i = 0; i < m; ++i) {
            int t1,t2,t3;
            cin >> t1 >> t2 >> t3;
            side.push_back({t3, {t1, t2}});
        }
        sort(AI(side));
        int ans = 0;
        for (auto &[i, j] : side) {
            if (dsu.query(j.first)!=dsu.query(j.second)) {
                ans += i;
                dsu.modify(j.first, j.second);
            }
        }
        int te = dsu.query(1);
        bool flag = 1;
        for (int i = 2; i<=n; ++i) {
            flag = (te == dsu.query(i));
        }
        if (flag) cout << ans << endl;
        else cout << -1 << endl;
        cin >> n >> m;
    }
    
    
    return 0;
}
