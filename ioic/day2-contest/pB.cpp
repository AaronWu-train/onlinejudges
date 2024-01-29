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

bool check(int x, int y, int z) {
	return __gcd(x, y) + z == __gcd(y,z) + x &&
		   __gcd(x, y) + z == __gcd(x,z) + y; 
}
const ll nn = 1e6+5;

signed main(){_
	ll t, n; cin >> t;
	vector<ll> prc(nn, 1);
	prc[0] = prc[1] = 0;
	for (int i = 2; i <= nn; ++i) {
		for (int j = i*2; j <= nn; j += i) {
			prc[j]++;
		}
	}
	vector<ll> sum(nn, 0);
	for (int i = 1; i <= nn; ++i){
		sum[i] = sum[i-1] + prc[i]*3+1;
	}

	while (t--) {
	cin >> n;
	cout << sum[n] << endl;


	}
	return 0;
}
