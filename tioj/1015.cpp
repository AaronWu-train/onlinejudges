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
    ll m, n;
    
    
    while (cin >> m >> n && (m || n)) {
        if (m > n) swap(m, n);
        ll ans = 0;
        ans += m*(m*n + m + n + 1);
        ans -= ((m+1)*m/2)*(m+n+2);
        ans += m*(m+1)*(2*m+1)/6;
        cout << ans << endl;
    }
    return 0;
}
