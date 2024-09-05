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
	struct node {
		ll sum, rm, lm, mm;
		void set(node &l, node& r) {
			sum = l.sum + r.sum;
			rm = max(r.rm, l.rm + r.sum);
			lm = max(l.lm, r.lm + l.sum);

			mm = max(r.mm, l.mm);
			mm = max(mm, max(rm, lm));
			mm = max(mm, sum);
			mm = max(mm, l.rm + r.lm);

			//debug(sum, l.sum, r.sum);
			//debug(mm, l.mm, r.mm);
			//debug(lm, l.lm, r.lm);
			//debug(rm, l.rm, r.rm);
		}
	};

	int n;
	vector<node> seg;

	SegmentTree (int _n, vector<int>& arr) {
		n = _n;
		seg.resize(2*n + 5);
		for (int i = 0; i < n; ++i) {
			seg[i+n].sum = arr[i];
			seg[i+n].rm = max(0, arr[i]);
			seg[i+n].lm = max(0, arr[i]);
			seg[i+n].mm = max(0, arr[i]);
		}	
		for (int i = n-1; i > 0; --i) {
			seg[i].set(seg[i*2], seg[i*2+1]); 
		}
	}

	void modify (int i, int v) {
		seg[i+n].sum = v;
		seg[i+n].rm = max(0, v);
		seg[i+n].lm = max(0, v);
		seg[i+n].mm = max(0, v);

		i += n;
		i >>= 1;
		while (i) {
			debug(i);
			seg[i].set(seg[i<<1], seg[i<<1|1]);
			i >>= 1;
		}
	}
	
	ll query() {
		return seg[1].mm;
	}
};


signed main(){_
	int n, q; 
	cin >> n >> q;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	while (__builtin_popcount(arr.size()) != 1) arr.pb(0);

	SegmentTree s(arr.size(), arr);
	while (q--) {
		int i, v;
		cin >> i >> v;
		s.modify(i-1, v);
		cout << s.query() << endl;
	}

	return 0;
}
