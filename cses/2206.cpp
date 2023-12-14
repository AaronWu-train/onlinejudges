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
#define mid ((l+r)>>1)

struct SegmentTree {
	vector<ll> arr;
	SegmentTree (ll n) {
		arr.resize(4*n);	
	}	

	ll query(ll i, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= ql) return arr[i];
		if (qr <= mid) return query(i*2, l, mid, ql, qr);
		else if (ql > mid) return query(i*2+1, mid+1, r, ql, qr);
		else {
			return min(query(i*2, l, mid, ql, mid), query(i*2+1, mid+1, r, mid+1, qr));
		}	
	}

	void modify(ll i, ll l, ll r, ll p, ll v) {
		if (p <= l && r <= p) {
			arr[i] = v;
			return;
		}
		if (p <= mid) modify(i*2, l, mid, p, v);
		else modify(i*2+1, mid+1, r, p, v);
		arr[i] = min(arr[i<<1], arr[i<<1|1]);
	}
};


signed main(){_
	ll n, q;
	cin >> n >> q;
	vector<int> arr(n+1);
	SegmentTree up(n+1);
	SegmentTree down(n+1);
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];	
		up.modify(1, 1, n, i, arr[i] + i);
		down.modify(1, 1, n, i, arr[i] - i);
	}
	while(q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int p, x;
			cin >> p >> x;
			up.modify(1, 1, n, p, x + p);
			down.modify(1, 1, n, p, x - p);
		}
		else {
			int i; cin >> i;
			cout << min(up.query(1, 1, n, i, n) - i, down.query(1, 1, n, 1, i) + i) << endl;
		}
	}

	return 0;
}
