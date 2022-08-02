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
const int mod = 998244353;
inline ll mabs(ll a) {
    return (a%mod+mod)%mod;
}
inline ll madd(ll a, ll b) {
    return mabs(a%mod + b%mod);
}
inline ll mmul(ll a, ll b) {
    return mabs(a * b % mod);
}
inline ll mpow(ll a, ll n) {
    ll ans = 1;
    for (int i = 1; i <= n; i <<= 1) {
        if (i & n) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
inline ll mdiv(ll a, ll b) {
    return mmul(a,  mpow(b, mod-2))%mod;
}
ll frac[1005] = {0};
inline ll c(ll a, ll b) {
    if (b > a) return 0;
    return mdiv(frac[a], mmul(frac[b], frac[a-b]))%mod;
}


signed main() {_
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll>a(n+1);
    vector<ll>b(m+1);
    frac[0] = frac[1] = 1;
    for (ll i = 2; i <= 1000; ++i) {
        frac[i] = mmul(frac[i-1], i);
    }

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    ll ans = 0;
    
    vector<ll>ansa(n+5, 0);
    vector<ll>ansb(m+5, 0);

    for (int r = 1; r <= k; ++r) {
        for (int i = 1; i <= n; ++i) ansa[i] = c(i-1, r-1) * c(n-i, k-r) % mod;
        for (int i = 1; i <= m; ++i) ansb[i] = c(i-1, r-1) * c(m-i, k-r) % mod;
//        OI(AI(ansa));
//        OI(AI(ansb));
        int j = 1;
        ll pre = 0;
        for (int i = 1; i <= n; ++i) {
            while (b[j] < a[i] && j <= m) {
                pre = pre + ansb[j];
                pre -= (pre >= mod)? mod : 0;
//                debug(pre);
                j++;
            }
            ans = ans + ansa[i] * pre % mod;
            ans -= (ans >= mod)? mod : 0;
//            debug(ans);
        }
    }
    
    
    
    cout << mdiv(ans, mmul(c(n, k), c(m, k))) << endl;
    
    
    return 0;
}
