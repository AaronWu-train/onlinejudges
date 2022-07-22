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

ll mpow(ll a, ll n) {
    int ans = 1;
    for (int i = 1; i <= n; i<<=1) {
        if (i & n) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
vector<ll> frac(2000010, 1);

signed main() {_
    int t;
    cin >> t;
    for (int i = 1; i <= 2000005; ++i) {
        frac[i] = i * frac[i-1] % mod;
    }
    OI(frac.begin(), frac.begin()+15);
    while (t--) {
        int n;
        cin >> n;
        n/=2;
        ll ans = frac[2*n] * mpow(frac[n], mod-2) % mod * mpow(frac[n], mod-2) % mod;
        ll temp = (frac[2*n] * mpow(frac[n+1], mod-2) % mod * mpow(frac[n-1], mod-2) % mod);
//        debug(temp);
        ans = ((ans - temp)%mod +mod)%mod;
        cout << ans << endl;
    }
    return 0;
}
