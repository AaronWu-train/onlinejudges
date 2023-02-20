#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
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
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;

	int mx = 0,  cs = 0;
	for (int i = 0; i < n; ++i) {
		cs = max(0ll, cs) + arr[i];
		mx = max(mx, cs);
	}
	int amx = arr[0];
	for (int i = 1; i < n; ++i) amx = max(amx, arr[i]);
	if (mx == 0 && mx > amx) cout << amx << endl;
	else cout << mx << endl;


	return 0;
}
