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
	vector<int> cnt(26, 0);
	int n; cin >> n;
	string s; cin >> s;
	int maxcnt = 0;
	int mincnt = n+1;
	int maxind = 0;
	int minind = 0;

	for (auto &i : s) {
		i -= 'a';
		cnt[i]++;
	}

	for (int i = 0; i < n; ++i) {
		if (cnt[s[i]] >= maxcnt) {
			maxcnt = cnt[s[i]];
			maxind = i;
		}
		if (cnt[s[i]] <= mincnt) {
			mincnt = cnt[s[i]];
			minind = i;
		}
	}
	if (s[minind] == s[maxind]) {
		for (int i = 0; i < n; ++i) {
			if (cnt[s[i]] == maxcnt && s[i] != s[maxind]) {
				mincnt = cnt[s[i]];
				minind = i;
				break;
			}
		}
	}
	for (auto &i : s) i += 'a';
	s[minind] = s[maxind];
	cout << s << endl;

}

signed main(){_
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
