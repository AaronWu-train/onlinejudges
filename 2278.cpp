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
const int mod = 1e9+7;
signed main(){_
	ll n, cur;
	cin >> n >> cur;
	ll dp[200005] = {0};
	ll sum = 0;
	sum = dp[cur]=1;
	for(int i = 0; i < n-1; ++i) {
		cin >> cur;
		ll k = sum - dp[cur];
		if (k < 0) k += mod;
		sum += k;
		dp[cur] += k;
		sum %= mod;
		dp[cur] %= mod;
	}
	cout << sum << endl;
	return 0;
}
