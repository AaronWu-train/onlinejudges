// status: TLE
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
struct BIT {
	int n;
	map<int, int> arr;

	BIT (int _n) {
		n = _n;
	}

	int query(int i) {
		int ans = 0;
		for(; i > 0; i -= (i&-i)) {
			ans += arr[i];
		}
		return ans;
	}

	void modify(int i, int v) {
		for (; i <= n; i += (i&-i)){ 
			arr[i] += v;
		}
	}

};

signed main(){_
	int n, q;
	cin >> n >> q;
	vector<int> arr(n+4);
	BIT bit(1e9+5);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		bit.modify(arr[i], 1);
	}
	while (q--) {
		char tp;
		cin >> tp;
		if (tp == '?') {
			int a, b;
			cin >> a >> b;
			int lb = bit.query(a-1);
			int rb = bit.query(b);
			cout << rb - lb << endl;
		} else if (tp == '!') {
			int i, v;
			cin >> i >> v;
			bit.modify(arr[i], -1);
			arr[i] = v;
			bit.modify(arr[i], 1);
		}
	}



	return 0;
}
