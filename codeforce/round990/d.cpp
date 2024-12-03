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

void solve() {
	int n;
	cin >> n;
	deque<int> arr(n);
	for (auto &i : arr) cin >> i;
	
	deque<int> ans;
	priority_queue<int, vector<int>,greater<int>> narr;
	
	while (!arr.empty()) {
		while (!ans.empty() && ans.back() > arr.front()) {
			narr.push(ans.back() + 1);
			ans.pop_back();
		}
		ans.pb(arr.front());
		arr.pop_front();
	}
	while (!narr.empty()) {
		while (!ans.empty() && ans.back() > narr.top()) {
			narr.push(ans.back() + 1);
			ans.pop_back();
		}
		ans.pb(narr.top());
		narr.pop();
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

signed main(){_
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
