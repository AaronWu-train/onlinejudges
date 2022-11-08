#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(...) 0
//#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mpow(ll a, ll n) {
	ll ret = 1;
	for (int i = 1; i <= n; i*=2) {
		if (i&n) ret *= a;
		a = a * a;
	}	
	return ret;
}

signed main(){_
	ll n;
	cin >> n;
	ll m = 1;
	ll k = 0;
	if (n < 10) {
		cout << 1 << endl;
		return 0;
	}
	while (m < n) {
		m *= 10;
		k++;
	}
	m /= 10; k--;
	ll dp[20] = {0};
	dp[0] = 1;
	for (int i = 1; i < 18; ++i) {
		dp[i] = dp[i-1] + mpow(10, i);
	}
	for(int i = 1; i < 18; ++i) {
		dp[i] += dp[i-1];
	}
	ll ans;
	if (n >=2*m) {
		ans = dp[k];
		debug(ans, 'n');
	} else {
		auto s = to_string(n);
		int i = 0;
		string s2 = "";
		assert(s[0] == '1');
		for (auto j : s) {
			if (j != '1') break;
			i++;
			s2 += '1';
		}
		debug(i);

		int j = s.size()-i;
		int h = n - stoll(s2)*pow(10, j);
		ans = i * (h + 1) + dp[k - 1];
		if (j>0 && s[i] > '1') {
			ans += dp[j-1];
			if (j - 2 >= 0) ans -= dp[j-2];
		}
		debug(ans, j);
		for (i-=1; i > 0; i--){
			ans += i * pow(10, j);
			debug(ans, j);
			j++;
		}
	}
	cout << ans << endl;


	return 0;
}
