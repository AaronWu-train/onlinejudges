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
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size();
		int ans = 0;
		char ls = s[0];
		int lsid = 0;
		for (int i = 0; i < n-1; ++i) {
			if (s[i] == s[i+1]) {
				ans++;
				if (ls == s[i] && lsid != i) {
					ans++;
				}
				lsid = i+1;
				ls = s[i+1];
			}
		}
		ans++;
		if (s[n-1] == ls && lsid != n-1) {
			ans++;
		}
		cout << ans << endl;
	}
	

	return 0;
}
