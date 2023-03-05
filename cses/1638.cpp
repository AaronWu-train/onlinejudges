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
const int mod = 1e9 + 7;

signed main(){_
	int n;
	cin >> n;
	vector<string> arr(n);
	for (auto &i : arr) cin >> i;
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i > 0 && arr[i-1][j] == '.') dp[i][j] += dp[i-1][j];
			if (j > 0 && arr[i][j-1] == '.') dp[i][j] += dp[i][j-1];
			if (arr[i][j] == '*') dp[i][j] = 0;
			dp[i][j] %= mod;
		}
	}
	cout << dp[n-1][n-1] << endl;

	return 0;
}
