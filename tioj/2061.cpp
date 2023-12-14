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
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(2, vector<int>(n+1, 0));
	vector<vector<string>> f(2, vector<string>(n+1));
	string r = s;
	std::reverse(AI(r));
	s = "#" + s;
	r = "#" + r;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i] == r[j]) {
				dp[i%2][j] = dp[(i-1)%2][j-1]+1;
				if (f[(i-1)%2][j-1].size() < 1000) {
					f[i%2][j] = f[(i-1)%2][j-1] + s[i];
				} else {
					cout << f[(i-1)%2][j-1] << endl;
					return 0;
				}
			}
			else {
				if (dp[i%2][j-1] > dp[(i-1)%2][j]) {
					dp[i%2][j] = dp[i%2][j-1];
					f[i%2][j] = f[i%2][j-1];
				}
				else{ 
					dp[i%2][j] = dp[(i-1)%2][j];
					f[i%2][j] = f[(i-1)%2][j];
				}
			}
		}
	}
	debug(dp[n%2][n]);
	cout << f[n%2][n]<< endl;

	return 0;
}
