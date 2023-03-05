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
	vector<int> dp(m+5);
	vector<int> w(n);
	vector<int> v(n);
	for (auto &i : w) cin >> i;
	for (auto &i : v) cin >> i;
	for (int i = 0; i < n; ++i) {
		for (int j = m; j > 0; --j) {
			if (j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m] << endl;

	return 0;
}
