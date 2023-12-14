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
	int n, k;
	cin >> n >> k;
	string temp; cin >> temp;
	vector<int> on(n);
	vector<ll> v(n);
	on[0] = temp[0] - '0';
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if(i) v[i] += v[i-1];
		if(i) on[i] += on[i-1] + temp[i] - '0';
	}
	deque<pair<ll,ll>> mono;
	mono.push_back({0, 0});
	ll ans = 0;
	for (int i = 0; i < n; ++i) { 
		while (!mono.empty() && on[i] - mono.front().second > k) {
			mono.pop_front();
		}
		ans = max(ans, v[i] - mono.front().first);
		while (!mono.empty() && mono.back().first > v[i]) {
			mono.pop_back();
		}
		mono.push_back({v[i], on[i]});
	}
	cout<<ans<<endl;

	return 0;
}
