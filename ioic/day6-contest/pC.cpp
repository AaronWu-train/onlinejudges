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
#define int long long

ll se(ll n, ll a) {
	ll l = 0, r = 2e9;
	while (l < r) {
		ll mid = l + (r - l)/2;
		if (mid*(mid + 1) >= 2*a) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

signed main(){_
	int t;
	cin >> t;
	while (t--) {
		int n, k; 
		cin >> n >> k;
		if (k == 0) {
			cout << 0 << endl;
			continue;
		}
		int a = n - k;

		ll r1 = se(n, k);
		if (((r1 * (r1+1)/2) - k) & 1) {
			if (r1 & 1) r1++;
			r1++;
		}

		ll r2 = se(n, a);
		if (((r2 * (r2+1)/2) - a) & 1) {
			if (r2 & 1) r2++;
			r2++;
		}

		ll ans = min(r1, r2);
		cout << ans << endl;
	}

	return 0;
}
