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
#define int long long
struct SegmentTree {
	int n;
	struct node {
		int v = 0;
		int size = 0;
		int tag = 0; 
		
		void add(int x) {
			tag += x;
			v += x * size;
		}
	};
	vector <node> arr;
	void init(int _n, vector<int>& _arr) {
		n = _n;
		arr.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			arr[i+n].v = _arr[i];
			arr[i+n].size = 1;
		}
		for (int i = n-1; i > 0; --i) {
			arr[i].v = arr[2*i].v + arr[2*i+1].v;
			arr[i].size = arr[2*i].size + arr[2*i+1].size;
		}
	}

	void pull(int x) {
		if (x == 1) return;
		pull(x>>1);
		if (arr[x>>1].tag) {
			arr[x].add( arr[x>>1].tag );
			arr[x^1].add( arr[x>>1].tag );
			arr[x>>1].tag = 0;
		}
	}
	
	void push(int i) {
		i >>= 1;
		while (i) {
			arr[i].v = arr[2*i].v + arr[2*i+1].v;
			arr[i].size = arr[2*i].size + arr[2*i+1].size;
			i >>= 1;
		}
	}

	void modify (int l, int r, int x) {
		l += n;
		r += n;
		int sl = l;
		int sr = r;
		pull(l);
		pull(r-1);
		while (l < r) {
			if (l&1) arr[l++].add(x);
			if (r&1) arr[--r].add(x);
			r >>= 1; l >>= 1;
		}	
		push(sl);
		push(sr-1);
	}	
	
	int query(int x) {
		x += n;
		pull(x);
		return arr[x].v;
	}
}st;


signed main(){_
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	st.init(n, arr);
	for (int i = 0; i < q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			st.modify(a-1, b, u);
		} else {
			int k;
			cin >> k;
			cout << st.query(k-1) << endl;
		}
	}		

	return 0;
}
