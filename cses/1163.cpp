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

signed main(){_
	int x, n;
	cin >> x >> n;
	multiset<int> loc = {0, x};
	multiset<int> seg = {x};
	while (n--) {
		int v; cin >> v;
		auto rit = *loc.lower_bound(v);
		auto lit = *prev(loc.lower_bound(v));
		seg.extract(rit - lit);
		seg.insert(rit-v);
		seg.insert(v-lit);
		loc.insert(v);
		cout << *seg.rbegin() << " ";
	}
	

	return 0;
}
