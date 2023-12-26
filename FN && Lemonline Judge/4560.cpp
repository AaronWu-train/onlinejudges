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

signed main(){_
	ll n;
	cin >> n;
	map<ll,ll> mp;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		b += a;
		mp[b] = a;
	}
	int m;
	cin >> m;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		auto it1 = mp.upper_bound(a);	
		auto it2 = mp.upper_bound(b);
		if (it1 != it2 ) continue;
		if ((it1 == mp.end() && it2 == mp.end()) || it1->second > b) {
			ans++;
		}


	}
	cout << ans << endl;
	return 0;
}
