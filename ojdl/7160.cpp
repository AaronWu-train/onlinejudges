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
	ll n, m, k, D;
	cin >> n >> m>> k >> D;
	vector<ll>arr(n);
	for(auto&i:arr)cin >> i;
	if (k > n) k = n;
	ll cur = m - k; // cur not in range
	ll ans = (m*(m+1) -  cur*(cur+1))/2;
	
	vector<ll>blocked(D);
	for(auto&i : blocked) cin >> i;
	sort(AI(blocked), greater<ll>());
	
	for (auto &i:blocked) {
		if (i < cur) break;
		debug(cur);
		ans -= i;
		if (cur > 0) ans += cur--;
		else k--;	
	}
	sort(AI(arr), greater<ll>());
	for (int i = 0; i < k && i < n; ++i) ans += arr[i];
	cout << ans << endl;

	return 0;
}
