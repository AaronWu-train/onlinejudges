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
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n, vector<ll>(2 * m + 5));
	int t;
	cin >> t;
	if (t) dp[0][t] = 1;
	else for (int i = 1; i <= m; ++i) dp[0][i] = 1; 

	for (int i = 1; i < n; ++i) {
		cin >> t;
		if (t) {
			dp[i][t] = dp[i-1][t-1] + dp[i-1][t] + dp[i-1][t+1];
			dp[i][t] %= mod;
		} else {
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
	}

	ll sum = 0;
	for (auto &i : dp[n-1]) sum = (sum + i) % mod;
	cout << sum << endl;	

	return 0;
}
