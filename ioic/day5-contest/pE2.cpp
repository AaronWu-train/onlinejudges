#pragma GCC optimize("Ofast, unroll-loops")
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
#define int long long
const ll magic = 20000;
signed main(){_
	ll n, m, k, t;
	cin >> n >> m >> k >> t;
	string s; cin >> s;

	vector<ll> a(n), b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') a[i] += t; 
	}
	vector<ll> dp(n, 1e18);
	dp[0] = 0;
	for (ll i = 0; i < n; ++i) {
		for (ll j = min(i+1, m*k); j > max(0ll, min(i, m*k) - magic); --j) {
			if (j % m == 0) {
				dp[j] = min(dp[j], dp[j-1] + a[i] + b[i]);
			}
			else {
				dp[j] = min(dp[j], dp[j-1] + a[i]);
			}	
		}
	}
	cout << dp[m*k] << endl;
	

	return 0;
}
