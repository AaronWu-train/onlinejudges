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

ll dp[1000005][2] = {0};
signed main(){_
	int t;
	cin >> t;
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < 1000001; ++i) {
		dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1]  )%mod;
		dp[i][1] = (dp[i-1][0]   + dp[i-1][1]*4)%mod;
	}

	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1])%mod << endl;	
	}

	return 0;
}
