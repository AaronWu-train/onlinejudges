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
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k*2< n) {
			cout << "NO" << endl;
			continue;
		}
		else if (k >= n) {
			cout << "YES" << endl;
			for (int i = 0; i < n-1; ++i) cout << 1 << " ";
			cout << k - n + 1 << endl;
		} 
		else {

			cout << "YES" << endl;
			int s = n - k;
			for (int i = 1; i <= n; ++i) {
				if (i&1 && s) {
					cout << 0 << " ";
					s--;
				}
				else {
					cout << 1 << " ";
				}
			}
			cout << endl;
		}
	}

	return 0;
}
