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
#define int long long

signed main(){_
	int n;
	cin >> n;
	int mx = 0;
	map<int,int> cnt;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		mx = max(mx, t);
		cnt[t]++;
	}
	bool flag = 1;
	for (auto &[i, j] : cnt) {
		if (j > 2) {
			flag = 0;
			break;
		}
	}
	if (cnt[mx] <= 1 && flag) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	
	return 0;
}
