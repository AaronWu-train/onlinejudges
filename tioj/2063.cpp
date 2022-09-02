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
	int n, q;
	cin >> n >> q;
	vector <long double> arr(n);
	for (auto &i : arr) cin >> i;
	for (int i = 1; i < n; ++i) {
		arr[i] *= arr[i-1];
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		if (arr[l-1] == 0 || l == 0) {
			 printf("%.9Lf\n", arr[r-1]);
	} 
		else printf("%.9Lf\n", arr[r-1]/arr[l-1]);
	}

	return 0;
}
