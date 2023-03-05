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

struct SegmentTree{
	vector<int> arr;
	int n;
	void init(int _n, vector<int>& _arr) {
		n = _n;
		arr.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			arr[i + n] = _arr[i];
		}
		for (int i = n-1; i > 0; --i) {
			arr[i] = max(arr[i<<1], arr[(i<<1)^1]);
		}
	}
	
	int query(int l, int r) {
		int ret = 0;
		l += n; r += n;
		while(l < r) {
			if (l&1) ret = max(ret, arr[l++]);
			if (r&1) ret = max(ret, arr[--r]);
			l >>= 1;
			r >>= 1;
		}
		return ret;
	}

	void modify(int i, int v) {
		i += n;
		arr[i] = v;
		while (i) {
			arr[i>>1] = max(arr[i], arr[i^1]);
			i >>= 1;
		}
	}
}st;



signed main(){_
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	st.init(n, arr);
//	OI(AI(st.arr));

	while (m--) {
		int x;
		cin >> x;
		if (st.arr[1] < x) {
			cout<<0<< " ";
			continue;
		}
		int l = 0, r = n;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			int k = st.query(l, mid);
			//debug(l,mid,r,k);
			if (k >= x) r = mid;
		   	else l = mid;	
		}
		cout << l+1 << " ";
		int ns = st.arr[l+n] - x;
		st.modify(l, ns);
	}
	
	return 0;
}
