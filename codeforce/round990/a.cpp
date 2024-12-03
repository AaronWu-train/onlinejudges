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


map<int, int> good;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int ans = 0;
	for (auto &i : arr) cin >> i;
	
	ans += good[arr[0]];
	for (int i = 1; i < n; ++i) {
		arr[i] += arr[i-1];
		ans += good[arr[i]];
	}
	cout << ans << endl;
}

signed main(){_
	good[1] = 1;;
	int s = 1;
	for (int i = 2; i < 206; i+=2) {
		s += 4*i;
		good[s] = 1;
		debug(s);
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
