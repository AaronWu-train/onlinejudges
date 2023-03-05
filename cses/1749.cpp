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

const int INF = 1e9 + 7;

struct SegmentTree {
	int n;
	vector<pair<int, int>> arr;
	
	void init(int _n, vector<int> vec) {
		n = _n;
		arr.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			arr[i + n] = {i, vec[i]};
		}
		for (int i = n - 1; i > 0; i--) {
			arr[i] = min(arr[i<<1], arr[i<<1^1]);
		}
	}

	pair<int, int> query(int l, int r) {
		l += n;
		r += n;
		pair<int, int> ret = {INF, -1};
		while (l < r) {
			if (l & 1) ret = min(ret, arr[l++]);
			if (r & 1) ret = min(ret, arr[--r]);
			l >>= 1; r >>= 1;
		}
		return ret;
	}

	void modify(int i) {
		i += n;
		arr[i] = {INF, -1};
		while (i > 1) {
			arr[i>>1] = min(arr[i], arr[i^1]);
			i >>= 1;
		}	
		debug(i);
		for (auto &i : arr) debug(i.first, i.second);
	}
}st;



signed main(){_
	int n;
	cin >> n;
	vector <int> vec(n);
	for (auto &i : vec) cin >> i;
	
	st.init(n, vec);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		x--;
		auto ret = st.query(x, n);
		debug(ret.first, ret.second);
		cout << ret.second << " ";
		st.modify(ret.first);
	}

	return 0;
}
