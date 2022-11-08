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
	int a, n;
	cin >> a >> n;
	int w[1005], v[1005];
	for (int i = 0; i < n; ++i) {
		cin >> v[i] >> w[i];
	}
	vector<int> dp(a+5, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = a; j > 0; --j) {
			if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]]+ v[i]);
		}
	}
	int ans = 0, c = 0;
	for (int i = 0; i <= a; ++i) if (dp[i] > ans) c = i, ans=dp[i];
	cout << ans << " " << c << endl;
	return 0;
}
