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

struct seg {
	int l;
	int r;
	int id;
	bool operator < (seg& b) {
		if (r == b.r) return l > b.l;
		return r < b.r;
	}
};

signed main(){_
	int n;
	cin >> n;
	vector<seg> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].l >> arr[i].r;
		arr[i].id = i;
	}
	sort(AI(arr));

	vector<int> mx(n+1), mn(n+1, 1e9);
	vector<int> st1(n), st2(n);
	for (int i = 0; i < n; ++i) {
		st1[arr[i].id] = (arr[i].l <= mx[i-1]);
		mx[i] = max(mx[i-1], arr[i].l);
	}

	for (int i = n - 1; i >= 0; --i) {
		st2[arr[i].id] = (arr[i].l >= mn[i+1]);
		mn[i] = min(mn[i+1], arr[i].l);
		debug(arr[i].l, mn[i]);
	}
	
	for (auto &i : st1) cout << i << " "; cout << endl;
	for (auto &i : st2) cout << i << " "; cout << endl;
	return 0;
}
