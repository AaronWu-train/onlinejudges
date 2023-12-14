#pragma GCC optimize("Ofast", "unroll-loop")
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
const int mod = 1000000007;
signed main(){_
	vector<ll> arr(10005);
	arr[0] = arr[1] = 1;
	for (int i = 2; i < 10005; ++i) {
		arr[i] = arr[i-1] + arr[i-2];
		if (arr[i] >= mod) arr[i] -= mod;
	}	
	ll q, t;
	cin >> q;
	while(q--) {
		cin >> t;
		cout << arr[t] << endl;
	}
	return 0;
}
