#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 998244353;
ll mpow(ll a, ll n) {
	ll r = 1;
	for (ll i = 1; i <= n; i<<=1) {
		if (i&n) r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}
ll frac[1e6+5];
ll minv(ll x) {
	return mpow(x, mod-2);
}

ll ncm(ll n, ll m) {
	return frac[n]*minv(frac[m])*minv(frac[n-m]);
}

signed main(){_
	frac[0]=1;
	for (int i = 1; i <= 1e6; ++i) {
		frac[i] = i*frac[i-1]%mod;
	}
	ll t, n; cin >> t >> n;
	while (t--) {
		
	}
	
	return 0;
}
