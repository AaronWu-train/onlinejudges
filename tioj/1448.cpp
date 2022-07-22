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
const int maxn = 1500005;

struct DJS{
    int arr[maxn] = {0};
    int n;
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
    }
    int query(int x){
        if (arr[x] == x) return x;
        arr[x] = query(arr[x]);
        return arr[x];
    }
    void modify(int x, int y) {
        if (arr[x] == arr[y]) return;
        int a = query(x);
        int b = query(y);
        arr[a] = b;
    }
}djs;


signed main() {_
    int n, k;
    cin >> n >> k;
    djs.init(n*3);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int d, x, y;
        cin >> d >> x >> y;
        x--; y--;
        if ( x >= n || y >= n || (d==2 && x==y)){
            ans++;
            debug("EEE");
            continue;
        }
        int t = djs.query(x);
        int t2 = djs.query(x + n);
        int t3 = djs.query(x + 2*n);
        int v = djs.query(y);
        int v2 = djs.query(y + n);
        int v3 = djs.query(y + 2*n);
        debug(t,t2,t3,v,v2,v3);
        // x eat y, 0 eat 1 eat 2 eat 0
        if (d == 1) {
            if (v == t2 || v == t3 || v2 == t || v2 == t3 || v3 == t || v3 == t2) {
                debug("GGG");
                ans++;
            }
            else {
                djs.modify(x, y);
                djs.modify(n + x, n + y);
                djs.modify(2*n + x, 2*n + y);
            }
        }
        if (d == 2){
            if (v2 == t2 || v2 == t3 || v3 == t || v3 == t3 || v == t || v == t2) {
                debug("KKK");
                ans++;
            }
            else {
                djs.modify(x, y + n);
                djs.modify(x + n, y + 2 * n);
                djs.modify(x + 2 * n, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
