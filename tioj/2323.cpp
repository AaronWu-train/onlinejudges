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
#define pll pair<ll,ll>
#define int long long

struct BIT {
    int n;
    vector<ll> arr;
    void init(int _n) {
        n = _n;
        arr.resize(n+5);
    }

    void modify(int i, ll v) {
        for (i; i <= n; i+=(i&-i)) {
            arr[i] += v;
        }
    }

    ll query(int i) {
        ll ans = 0;
        for (i; i > 0; i-=(i&-i)) {
            ans += arr[i];
        }
        return ans;
    }
} bit;

signed main(){_
	int n, q;
	cin >> n >> q;
	vector<int> w(n+5);
	vector<int> h(n+5);
	for (int i = 1; i <= n; ++i) cin >> h[i];
	for (int i = 1; i <= n; ++i) cin >> w[i];
	vector<int> l(n+5), r(n+5);

	vector<pll> mono;
	mono.pb({0, 1e18});
	for (int i = 1; i <= n; ++i) {
		while (!mono.empty() && mono.back().second <= h[i]) mono.pop_back();
		l[i] = mono.back().first;
		mono.push_back({i, h[i]});
	}

	mono.clear();
	mono.pb({n+1, 1e18});
	for (int i = n; i > 0; --i) {
		while (!mono.empty() && mono.back().second <= h[i]) mono.pop_back();
		r[i] = mono.back().first - 1;
		mono.push_back({i, h[i]});
	}
	OI(AI(l));
	OI(AI(r));
	
	bit.init(n+5);
	for (int i = 1; i <= n; ++i) {
		bit.modify(i, w[i]);
	}

    while(q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            bit.modify(p, -w[p]);
            w[p] = x;
            bit.modify(p, w[p]);
        } else {
            int p;
            cin >> p;
            int lq = bit.query(l[p]);
            int rq = bit.query(r[p]);
            cout << rq - lq << endl;
        }
    }	


	return 0;
}
