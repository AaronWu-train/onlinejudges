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
	int m, p, n;
	cin >> m >> p >> n;
	vector<int> arr(n);
	for (auto &i:arr) cin >> i;
	int cur = 0;
	int ans = 0;
	arr.push_back(p);
	for (int i = 0; i <= n; ++i) {
		if (cur + m < arr[i]) {
			ans++;
			cur = arr[i-1];
			if (cur + m < arr[i]) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
