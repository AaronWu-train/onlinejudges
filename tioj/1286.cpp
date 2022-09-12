#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int mod = 1e6;

ll mpow(ll a, ll n) {
	ll ans = 1;
	for (int i = 1; i <= n; i*=2) {
		if (i & n) ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}

int main(){_
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = 0;
	while (a <= d) {
		ans = (ans + mpow(a, c)) % mod;
		a = a + b;
	}	
	cout << ans << endl;
	return 0;
}
