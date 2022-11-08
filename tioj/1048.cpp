// TLE

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
	int arr[15];
	arr[0] = 1;
	for (int i = 1; i < 13;++i) arr[i] = i * arr[i-1];
	while (cin >> n >> m && (n || m)) {
		int k = (m -1)% arr[n];
		vector<char> ans;
		for (int i = 0; i < n; ++i) {
			ans.pb('A'+(i)%n);
		}
		for (int i = 0; i < k; ++i) next_permutation(AI(ans));
		for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
	}


	return 0;
}
