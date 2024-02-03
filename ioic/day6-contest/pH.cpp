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
const int mod = 998244353;
signed main(){_
	const int mxn =1e6+5;
	vector<int> dp(mxn);
	vector<int> sum(mxn);
	vector<int> ss(mxn);
	for (int i = 1; i < mxn; ++i) {
		dp[i] = (ss[i-1] + i)%mod;
		sum[i] = (sum[i-1] + dp[i])%mod;
		ss[i] = (ss[i-1] + sum[i])%mod;
	}	
	int t; cin >> t;
	while (t--) {
		int i; cin >> i;
		cout << dp[i] << endl;
	}	

	return 0;
}
