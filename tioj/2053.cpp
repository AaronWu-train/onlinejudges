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
const int mod = 1e9+7;
const int w = 2;
struct mat{
    ll c[w][w] = {0};
    void init(ll k[w][w]) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < w; ++j) {
                c[i][j] = k[i][j];
            }
        }
    }
};
mat operator * (mat a, mat b) {
    mat ret;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < w; ++k) {
                ret.c[i][j] = (ret.c[i][j] + a.c[i][k] * b.c[k][j] % mod) % mod;
            }
        }
    }
    return ret;
}
mat pow(mat a, int n) {
    mat ret;
    ret.c[0][0] = ret.c[1][1] = 1;
    for (int i = 1; i <= n; i <<= 1) {
        if (i & n) ret = ret * a;
        a = a * a;
    }
    return ret;
}

signed main() {_
    int x1, x2, a, b, n;
    cin >> x1 >> x2 >> a >> b >> n;
    mat k;
    ll temp[w][w] = {{0, 1}, {a, b}};
    k.init(temp);
    k = pow(k, n-2);
    mat as;
    as.c[0][0] = x1;
    as.c[1][0] = x2;
    k = k * as;
    cout << k.c[1][0] << endl;
    
    return 0;
}
