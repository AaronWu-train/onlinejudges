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

struct SegmentTree {
	int n;
	vector<ll> st;
	SegmentTree (int _n, vector<int> & arr) {
		n = _n;
		st.resize(2*n+5, LLONG_MAX);
		for (int i = 0; i < n; ++i) {
			st[i+n] = arr[i];
		}
		for (int i = n-1; i > 0; --i) {
			st[i] = min(st[i<<1], st[i<<1|1]);
		}
	}
	void modify(int p, int v) {
		p += n;
		st[p] = v;
		for (p >>= 1; p > 0; p >>= 1) {
			st[p] = min(st[p<<1], st[p<<1|1]);
		}
	}
	
	ll query(int l, int r) {
		l += n; r += n;
		ll ret = LLONG_MAX;
		while (l < r) {
			if (l&1) ret = min(ret, st[l++]);
			if (r&1) ret = min(ret, st[--r]);
			l >>= 1; r >>= 1;
		}
		return ret;
	}
};

signed main(){_
	ll n, q;
	cin >> n >> q;
	vector<int> arr(n+1), uu(n+1), dd(n+1);
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];	
		uu[i] = arr[i] + i;
		dd[i] = arr[i] - i;
	}
	SegmentTree up(n+1, uu);
	SegmentTree down(n+1, dd);

	while(q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int p, x;
			cin >> p >> x;
			up.modify(p, x + p);
			down.modify(p, x - p);
		}
		else {
			int i; cin >> i;
			cout << min(up.query(i, n+1) - i, down.query(1, i+1) + i) << endl;
		}
	}



	return 0;
}
