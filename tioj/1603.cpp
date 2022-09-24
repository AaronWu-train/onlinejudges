#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define int ll

struct SegmentTree {
	struct node {
		int mx;
		int mn;
	};
	int n;
	vector<node> arr; 

	void init(int _n, vector<int>& in) {
		n = _n;
		arr.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			arr[i+n] = {in[i], in[i]};
		}
		for (int i = n-1; i > 0; --i) {
			arr[i].mx = max(arr[2*i].mx, arr[2*i+1].mx);
			arr[i].mn = min(arr[2*i].mn, arr[2*i+1].mn);
		}
		for (auto i : arr) debug(i.mx, i.mn);
	}
	int query(int l, int r) {
		l += n;
		r += n;
		int mx = INT_MIN;
		int mn = INT_MAX;
		while (l < r) {
			if (l&1) {
				mx = max(mx, arr[l].mx);
				mn = min(mn, arr[l++].mn);
			} 
			if (r&1) {
				mx = max(mx, arr[--r].mx);
				mn = min(mn, arr[r].mn);
			}
			l >>= 1; r >>= 1;
		}
		return mx - mn;
	}
}st;



signed main(){_
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (auto&i : arr) cin >> i;
	st.init(n, arr);
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		cout << st.query(l-1, r) << endl;
	}

	return 0;

}
