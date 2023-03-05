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

const int mod = 1e9+7;

signed main(){_
	int n;
	cin >> n;
	vector<int> arr(22);
	for (int i = 1; i <= 6; ++i) arr[i] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i > 6) arr[i % 10] = 0;
		for (int j = 1; j <= 6 && i - j > 0; ++j) {
			arr[i % 10] += arr[(i - j) % 10];
			arr[i % 10] %= mod;
		}	
	}
	cout << arr[n%10] << endl;
	return 0;
}
