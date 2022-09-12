#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

int main(){_
	int n;
	while( cin >> n && n) {
		vector< vector<ll> > arr(n, vector<ll>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == 0) arr[i][j] = INT_MAX;
				if (i == j) arr[i][j] = 0;
			}
		}
		ll ans = INT_MAX;
		auto dis = arr;
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					ans = min(ans, dis[i][j] + arr[j][k] + arr[k][i]);
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		if (ans == INT_MAX) cout << -1 << endl;
		else cout << ans << endl;
	}

	return 0;
}
