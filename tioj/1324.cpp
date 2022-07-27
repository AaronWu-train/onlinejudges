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


ll mpow(ll a, ll n, ll mod) {
    if(mod<=1) return 0;
    if(n==0) return 1;
    if(a==0) return 0;
    ll ans = 1;
    for (int i = 1; i <= n; i *= 2) {
        if (i & n) ans = a * ans % mod;
        a = a * a % mod;
    }
    return ans;
}

signed main() {_
    int m;
    while (cin >> m && m) {
        vector<ll>arr(m);
        for (auto &i : arr) cin >> i;
        ll mod;
        cin >> mod;
        ll ans = arr[m-1];
        for (int i = m-2; i >= 0; --i) {
            ans = mpow(arr[i], ans, mod-i);
        }
        cout << ans << endl;
        
    }
    return 0;
}
