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

signed main() {_
    int t;
    cin >> t;
    int k = 0;
    ll f[40] = {0};
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= t; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    OI(AI(f));
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < f[i]; ++j) {
            k++;
            k -= (k>=3)?3:0;
            cout << k;
        }
        cout << endl;
    }
    
    return 0;
}
