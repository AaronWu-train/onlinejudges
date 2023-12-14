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

struct BIT {
	vector<int> arr;
	int n;
	void init(int _n) {
		n = _n;
		arr.resize(n+5);
	}

	void modify(int i, int v) {
		for (i; i <= n; i += (i&-i)) {
			arr[i] += v;
		}
	}

	int query(int i) {
		int ans = 0;
		for (i; i > 0; i -= (i&-i)) {
			ans += arr[i];
		}
		return ans;
	}
}bit;


signed main(){_
	
	int n;
	cin >> n;
	bit.init(n+5);
	vector<int> arr(n+5);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		bit.modify(i, 1);
	}
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r)/2;
			if (bit.query(mid) >= t) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		cout << arr[l] << " ";
		bit.modify(l, -1);
	}

	return 0;
}
