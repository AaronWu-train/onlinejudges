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

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i-1].first;
		arr[i-1].second = i;
	}
	sort(AI(arr), greater<pair<int, int>>());
	vector<int> b(n+1);
	for (int i = 1; i <= n; ++i) {
		b[arr[i-1].second] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

}



signed main(){_
	int t;
	cin >> t;
	while (t--){ 
		solve();
	}

	return 0;
}
