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
	ll n, m, k, t;
	cin >> n >> m >> k >> t;
	string s; cin >> s;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll tmp; cin >> tmp;
		if (s[i]== '1') arr.pb(tmp);
		else arr.pb(tmp + t);
	}
	sort(AI(arr));
	ll ans = 0;
	for (int i = 0; i < m*k;++i) {
		ans += arr[i];
	}
	cout << ans << endl;
	return 0;
}
