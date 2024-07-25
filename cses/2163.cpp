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
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<typename T> using rbt = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){_
	int n, k;
	cin >> n >> k;
	int pt = 0;
	rbt<int> t;
	for (int i = 1; i <= n; ++i) {
		t.insert(i);
	}
	while (!t.empty()) {
		pt = (pt + k) % t.size();
		auto k = t.find_by_order(pt);
		cout << *k << " ";
		t.erase(k);
	}

	return 0;
}
