#include <bits/stdc++.h>
#include <functional>
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
double pi = 3.14159265358;

signed main() {_
    int n;
    cin >> n;
    double ans = 0;
    ll sumx = 0;
    ll sumy = 0;
    
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        ans += x * x + y * y;
        sumx += x;
        sumy += y;
    }
    ans = ans * n * 2 - 2 * ((double)sumx * sumx + (double)sumy * sumy);
    cout << fixed << setprecision(9) << ans * pi / 4 << endl;
    return 0;
}
