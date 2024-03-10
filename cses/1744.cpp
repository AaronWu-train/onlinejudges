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
	int a, b;
	cin >> a >> b;
	ll ans = 0;
	vector<vector<ll>> dp(a+1, vector<ll>(b+1, 1e9+7));
	for (auto &i : dp[0]) i = 0;
	for (int i = 1; i <= b; ++i) dp[0][i] = 0;
	for (int i = 1; i <= min(a, b); ++i) dp[i][i] = 0;

	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			for (int k = 1; k < i; ++k) {
				dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j] + 1);
			}
			for (int k = 1; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
		}
	}
	cout << dp[a][b] << endl;


	return 0;
}
