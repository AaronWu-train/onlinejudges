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
	struct Node {
		ll sum = 0;
		ll down = -1;
		ll top = -1;
		void addtop(Node b) {
			if (b.down == -1) {
				return;
			}
			if (top == -1){
				sum += b.sum;
				down = b.down;
				top = b.top;
			}
			else {
				sum += b.sum;
				sum += b.down^top;
				top = b.top;
			}
		}
	};

	vector<Node> arr;
	int n;

	void init(int _n) {
		n = _n;
		arr.resize(2*n+5);
	}	

	void pull(int i) {
		i /= 2;
		if (!i) return;
		pull(i);
		arr[2*i].addtop(arr[i]);
		arr[2*i+1].addtop(arr[i]);
		arr[i].top = arr[i].down = -1;
		arr[i].sum = 0;
	}

	void modify(ll l, ll r, ll x) {
		l += n; r += n;
		pull(l);
		pull(r-1);
		while (l < r) {
			if (l & 1) arr[l++].addtop({0, x, x});
			if (r & 1) arr[--r].addtop({0, x, x});
			l/=2; r/=2;
		}
	}

	ll query(int i) {
		i += n;
		pull(i);
		return arr[i].sum;
	}	
}st;



signed main(){_
	int n, q;
	cin >> n >> q;
	st.init(n+1);
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			ll l, r, x; cin >> l >> r >> x;
			st.modify(l,r+1, x);
		}
		if (tp == 2) {
			int i; cin >> i;
			cout << st.query(i) << endl;
		}
	}

	return 0;
}
