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
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for (auto &i : c) cin >> i;
	sort(AI(c));
	vector<int> dp(x+5, 0);
	dp[0] = 1;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i + c[j] <= x; ++i) {
			dp[i + c[j]] += dp[i];
			dp[i + c[j]] %= mod;
		}
	}	

	
	cout << dp[x]<< endl;
	return 0;
}
