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
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 5);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		vector<int> s(k+5);
		s[0] = dp[0];
		for (int j = 1; j <= k; ++j) {
			s[j] = s[j-1] + dp[j];
			s[j] %= mod;
		}
		for (int j = k; j >= 0; --j) {
			if (j > a) dp[j] = (s[j] - s[j - a - 1] + mod) % mod;
			else dp[j] = s[j];
			dp[j] %= mod;
		}
	}
	cout << dp[k] << endl;	




	return 0;
}
