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
struct pt{
	int l;
	int r;
	bool operator < (pt b) {
		if (r == b.r) return l < b.l;
		return r < b.r;
	}
};

signed main(){_
	int n;
	cin >> n;
	vector<pt> arr(n);
	for (auto &i : arr) cin >> i.l >> i.r;
	sort(AI(arr));
	int ans = 0, curr = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i].l >= curr) {
			ans++;
			curr = arr[i].r;
		}
	}
	cout << ans << endl;


	return 0;
}
