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

struct DJS{
    int n;
    int fa[10005] = {0};
    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
    }
    int query(int i) {
        if (fa[i] == i) return i;
        fa[i] = query(fa[i]);
        return fa[i];
    }
    void modify(int a, int b) {
        int ha = query(a);
        int hb = query(b);
        if (ha < hb) fa[hb] = ha;
        else fa[ha] = hb;
    }
};


signed main() {_
    int n, m;
    while (cin >> n >> m) {
        DJS djs;
        djs.init(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            djs.modify(a, b);
        }
        int k;
        cin >> k;
        cout << djs.query(k) << endl;
    }
    return 0;
}
