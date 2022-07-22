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
ll a[22] = {0};
ll fun(ll x) {
    if (a[x] != 0) return a[x];
    if (x == 1) return 0;
    if (x == 2) return 1;
    
    a[x] = (x-1)*(fun(x-1) + fun(x-2));
    return a[x];
}


signed main() {_
    ll n;
    while (cin >> n && n) {
        cout << fun(n) << endl;
    }
    return 0;
}
