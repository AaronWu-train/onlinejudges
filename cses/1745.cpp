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
	int n; cin >> n;
	vector<int> arr(n);
	int sum = 0;
	for (auto &i : arr) {
		cin >> i;
		sum += i;
	}
	sort(AI(arr));
	vector<int> dp(sum+5);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = sum; j >= arr[i]; --j) {
			if (dp[j - arr[i]]) dp[j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= sum; ++i) {
		if(dp[i]) ans++;
	}
	cout << ans << endl;
	for (int i = 1; i <= sum; ++i) {
		if(dp[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}
