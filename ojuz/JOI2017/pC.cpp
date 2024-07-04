#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define AI(x) begin(x),end(x)
#define endl '\n'
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
int n, m; 
ll arr[2005][2005];

struct rr {
	ll v() {
		return max(umax-umin, dmax-dmin);
	}
	ll umax = INT_MIN;
	ll umin = INT_MAX;
	ll dmax = INT_MIN;
	ll dmin = INT_MAX;	
};

rr rrmin(rr a, rr b) {
	if (a.v() < b.v()) return a;
	return b;
}

rr jup(int a, int b) {
	rr cur, ret;
	for (int i = 0; i < b; ++i) {
		cur.umin = min(cur.umin, arr[a][i]);
		cur.umax = max(cur.umax, arr[a][i]);
	}
	for (int i = b; i < m; ++i) {
		cur.dmin = min(cur.dmin, arr[a][i]);
		cur.dmax = max(cur.dmax, arr[a][i]);
	}
	if (a < n-1) {
		for (int i = b; i < m; ++i) {
			rr k = jup(a+1, i);
			k.umax=max(k.umax, cur.umax);
			k.umin=min(k.umin, cur.umin);
			k.dmax=max(k.dmax, cur.dmax);
			k.dmin=min(k.dmin, cur.dmin);
			ret = rrmin(ret, k);
		}
	}
	return ret;
}

rr jdn(int a, int b) {
	rr ret, cur;
	for (int i = 0; i < b; ++i) {
		cur.umin = min(cur.umin, arr[a][i]);
		cur.umax = max(cur.umax, arr[a][i]);
	}
	for (int i = b; i < m; ++i) {
		cur.dmin = min(cur.dmin, arr[a][i]);
		cur.dmax = max(cur.dmax, arr[a][i]);
	}
	for (int i = 0; i < b; ++i) {
		rr k = jdn(a+1, i);
		k.umax=max(k.umax, cur.umax);
		k.umin=min(k.umin, cur.umin);
		k.dmax=max(k.dmax, cur.dmax);
		k.dmin=min(k.dmin, cur.dmin);
		ret = rrmin(ret, k);
	}
	return ret;
}


signed main() {_
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	rr ret;
	for (int i = 0; i < m; ++i) {
		ret = rrmin(ret, jdn(0, i));
		ret = rrmin(ret, jup(0, i));
	}
	cout << ret.v() << endl;
}