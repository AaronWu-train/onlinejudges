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
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	ll ans = 0;
	if (n == k * 2) {
		vector<int> last(k+1, -1);
		vector<int> pos(k+1, -1);
		for (int i = 0; i < k; ++i) {
			last[arr[i]] = i;
			pos[arr[i+k]] = i+k;
		}
		for (int i = 0; i < n; ++i) {
			int x = arr[i];
			while( pos[x] - i > k) {
				int y = arr[pos[x] - 1];
				swap(arr[pos[x]-1], arr[pos[x]]);
				pos[y]++; pos[x]--;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
