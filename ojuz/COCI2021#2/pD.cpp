#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef AaW 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9+7;

ll ADD(ll a, ll b){
	return (a%mod + b%mod)%mod;
}

ll SUB(ll a, ll b) {
	return ((a%mod - b%mod)%mod+mod)%mod;
}

ll MUL(ll a, ll b) {
	return (a%mod)*(b%mod)%mod;
}

ll POW(ll a, ll n) {
	ll ret = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (i&n) ret = ret * a % mod;
		a = a * a % mod;
	}
	return ret;
}

ll DIV(ll a, ll b) {
	ll k = POW(b, mod-2);
	return MUL(a, k);
}

signed main(){_
	int n, l;
	cin >> n >> l;
	vector<ll> arr(n);
	int rs = 0;
	int ans = 0;
	vector<ll> fact(l+5);
	fact[0] = 1;
	for (auto &i : arr) {
		cin >> i;
		rs += i;
	}
	for (int i = 1; i <= l; ++i) {
		fact[i] = MUL(fact[i-1], i);
	}
	if (n == 1) {
		cout << l << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int sp = l - (rs - (arr[i]-1) - (arr[j]-1));
			debug(rs, sp);
			ans = ADD(ans, DIV(fact[n-2+sp], fact[sp]));
		}	
	}
	cout << ans << endl;
	return 0;
}
