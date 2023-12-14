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
	vector<int> pi(s.size()+1);
	pi[0] = -1; pi[1] = 0;
	for (int i = 1; i < s.size(); ++i) {
		int j = pi[i];
		while (j >= 0 && s[i] != s[j]) j = pi[j];
		pi[i+1] = j+1;
	}
	vector<int> ans;
	int j = s.size();
	while (j > 0) {
		if (pi[j]) ans.pb(pi[j]);
		j = pi[j];
	}
	for (int i = 1; i <= ans.size(); ++i) {
		cout << ans[ans.size()-i] << " ";
	}

	return 0;
}
