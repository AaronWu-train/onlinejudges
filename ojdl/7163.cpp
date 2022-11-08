#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll __int128_t
#define int	__int128_t 
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

vector<int>canuse(10, 1);
int sw(int x, int n) {
	int ret = 0, i = 1;
	while(x) {
		ret += canuse[x%10]*i;
		x /= 10, i *= n;
	}
	return ret;
}

signed main(){_
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		canuse[temp] = 0;
	}
	canuse[0] = 0;
	OI(AI(canuse));
	for (int i = 1; i < 10; ++i) canuse[i] += canuse[i-1];
	OI(AI(canuse));
	int ans = 0;
	debug(n);
	string l, r;
	cin >> l >> r;
	while(r) {
		ans += sw(r, n - k);
		r /= 10;
		debug(ans);
	}
	while(l) {
		ans -= sw(l ,n - k);
		l /= 10;
	}
	cout << ans << endl;


	return 0;
}

