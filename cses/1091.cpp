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
	int n, m;
	cin >> n >> m;
	multiset<int> h;
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		h.insert(t);
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		auto k = h.upper_bound(t);
		if (k == h.begin() || h.empty()) {
			cout<<-1<<endl;
		}
		else{
			k--;
			cout << *k << endl;
			h.erase(k);
		}
	}
	


	return 0;
}
