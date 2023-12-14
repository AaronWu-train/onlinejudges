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

signed main(){_
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	a = "$"+a;
	b="#"+b;
	vector<vector<string>> dp(n+5, vector<string> (m+5));
	for (int i = 1; i <=n; ++i) {
		for (int j = 1; j <=m; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + string(1, a[i]);
			}else {
				if (dp[i][j-1].size() > dp[i-1][j].size()) dp[i][j] = dp[i][j-1];
				if (dp[i][j-1].size() < dp[i-1][j].size()) dp[i][j] = dp[i-1][j];
				if (dp[i][j-1].size() == dp[i-1][j].size()) dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
			}
			debug(i, j, dp[i][j]);
		}
	}
	if (dp[n][m] == "") cout << 7122 << endl;
	else cout << dp[n][m] << endl;

	return 0;
}
