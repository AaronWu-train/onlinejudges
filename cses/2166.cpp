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
const ll NINF = -1e18;
 
struct SegmentTree {
	struct node {
		ll val = NINF;
		ll tag = 0;
		void add(ll v) {
			val+=v;
			tag+=v;
		}
	};
 
	vector<node> st;
	ll n=0;
	
	SegmentTree (ll _n, vector<ll> arr) {
		n = _n;
		st.resize(2*n+5);
		for (ll i = 0; i < n; ++i) {
			st[i+n].val = arr[i];
		}
		for (ll i = n-1; i > 0; --i) {
			st[i].val = max(st[i<<1].val, st[2*i+1].val);
		}
	}
	
	void pull(ll x) {
		if (x == 1) return;
		pull(x >> 1);
		st[x].add(st[x>>1].tag);
		st[x^1].add(st[x>>1].tag);
		st[x>>1].tag = 0;
		return;
	}
	
	void push(ll i) {
		i >>= 1;
		while (i > 0) {
			st[i].val = max(st[i<<1].val, st[2*i+1].val);
			i >>= 1;
		}
	}	
	
	ll query(ll ql, ll qr) {
		ql += n; qr += n;
		ll l = ql; ll r = qr;
		pull(l); pull(r-1);
		pull(l+1); pull(r);
		ll mx = NINF;
		while (l < r) {
			if (l & 1) mx = max(mx, st[l++].val);
			if (r & 1) mx = max(mx, st[--r].val);
			l >>= 1; r >>= 1;
		}
		return mx;
	}
 
	void modify(ll ql, ll qr, ll v) {
		ql += n; qr += n;
		ll l = ql; ll r = qr;
		pull(l); pull(r - 1);
		pull(l+1); pull(r);
		while (l < r) {
			if (l & 1) st[l++].add(v);
			if (r & 1) st[--r].add(v);
			l >>= 1; r >>= 1;
		}
		push(ql); push(qr - 1);
	}
};
 
struct BIT {
	ll n;
	vector<ll> arr;
	void modify(ll i, ll v) {
		for (i; i <= n; i += (i&-i)) {
			arr[i] += v;
		}
	}
	
	ll query(ll i) {
		ll ans = 0;
		for (i; i > 0; i -=(i&-i)) {
			ans += arr[i];
		}
		return ans;
	}
 
	BIT(ll _n, const vector<ll> & s) {
		n = _n;
		arr.resize(n+5);
		for (ll i = 1; i <= n; ++i) {
			modify(i, s[i]);
		}
	}
};
 
signed main(){
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n+1);
	vector<ll> pre(n+1);
	for (ll i = 1; i <= n; ++i) {
		cin >> arr[i];
		pre[i] = arr[i] + pre[i-1];
	}	
 
	SegmentTree st(n+1, pre);
	BIT bit(n+1, arr);
 
	while (q--) {
		ll tp;
		cin >> tp;
		if (tp == 1) {
			ll k, u;
			cin >> k >> u;
			st.modify(k, n+1, u - arr[k]);
			bit.modify(k, u-arr[k]);
		   	arr[k] = u;	
		}
		else {
			ll a, b;
			cin >> a >> b;
			cout << max(0ll, st.query(a, b+1) - bit.query(a-1)) << endl;
		}
	}	
	return 0;
}
