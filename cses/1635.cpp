#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9+7;
signed main(){_
	int n, x;
	cin >> n >> x;
	vector<int> dp(x+10, 0);
	vector<int> c(n);
	for (auto &i : c) cin >> i;
	dp[0] = 1;
	for (int i = 0; i <= x; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i + c[j] <= x) {
				dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % mod;
			}
		}	
	}	
	if (dp[x] == 2e9) cout << -1 << endl;
	else cout << dp[x] << endl;
	return 0;
}

