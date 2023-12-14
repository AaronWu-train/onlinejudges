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
signed main() {_
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<bool>> al(n+5, vector<bool>(m+5));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			al[i][j] = (s[j-1] == 'o');
		}
	}

	vector<vector<int>> dp(n+5, vector<int>(m+5, 0));
	for (int k = 0; k <= q; ++k) {
		dp[1][1] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (i != 1 || j != 1) dp[i][j] = 0; 
				if (!al[i][j]) {continue;}
				if (al[i-1][j]) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
				if (al[i][j-1]) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
				if (al[i+1][j]) dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
				if (al[i][j+1]) dp[i][j] = (dp[i][j] + dp[i][j+1])%mod;
				debug(i, j, dp[i][j]);
			}
		}
	}
	cout << dp[n][m] << endl;


	return 0;
}
