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
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		int r = n + m;
		int l = max(0, n-m);
		int k = l ^ r;
		if (k == 0) cout << n << endl;
		else {
		int f = INT_MAX >> __builtin_clz(k);
		int ans = r | f;
		cout << ans << endl;
	}
	}
	return 0;
}
