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
	int n, m , k;
	cin >> n >> m >> k;
	vector<int> a(n);
	vector<int> b(m);
	for (auto&i : a) cin >> i;
	for (auto&j : b) cin >> j;
	sort(AI(a));
	sort(AI(b));

	int i = 0, j = 0, ans = 0;
	for (i = 0; i < n; ++i) {
		while(j < m && b[j] < a[i]-k) j++;
		if (j >= m) break;
		if (b[j] <= a[i]+k) ans++, j++;
	}
	cout << ans << endl;

	return 0;
}
