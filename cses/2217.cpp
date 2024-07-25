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
	int n, m;
	cin >> n >> m;
	vector<int> ind(n+2);
	vector<int> arr(n+2);
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		ind[arr[i]] = i;
	}
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		ans += (ind[i] > ind[i+1]);
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		int na = arr[a];
		int nb = arr[b];
		ans -= (ind[na-1] > ind[na]);
		ans -= (ind[na] > ind[na+1]);
		ans -= (ind[nb-1] > ind[nb]);
		ans -= (ind[nb] > ind[nb+1]);
		swap(ind[na], ind[nb]);
		swap(arr[a], arr[b]);
		ans += (ind[na-1] > ind[na]);
		ans += (ind[na] > ind[na+1]);
		ans += (ind[nb-1] > ind[nb]);
		ans += (ind[nb] > ind[nb+1]);
		cout << ans << endl;
	}

	return 0;
}
