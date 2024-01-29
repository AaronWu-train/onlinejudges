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

struct BIT {
	vector<int> v;
	int n;
	void init(int _n) {
		n = _n;
		v.resize(n+5);
	}
	void modify(int i, int val) {
		for (i; i <= n; i+=(i&-i)) {
			v[i] += val;
		}
	}
	int query(int i) {
		int ans = 0;
		for (i; i > 0; i -=(i&-i)) {
			ans += v[i];
		}
		return ans;
	}
}bit, b2;



signed main(){_
	int n;
	cin >> n;
	vector<int> arr(n+1, 0);
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	bit.init(n);
	b2.init(n);
	for (int i = 1; i <= n; ++i) bit.modify(i, arr[i]);
	for (int i = 1; i <= n; ++i) b2.modify(i, arr[i]*arr[i]);
	
	int q;
	cin >> q;
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int p, x;
			cin >> p >> x;
			bit.modify(p, x-arr[p]);
			b2.modify(p, x*x-arr[p]*arr[p]);
			arr[p] = x;
		} else {
			int l, r; cin >> l >> r;
			ll temp = bit.query(r) - bit.query(l-1);
			ll tem2 = b2.query(r) - b2.query(l-1);
			cout << (temp * temp - tem2)/2<< endl;
		}
	}




	return 0;
}
