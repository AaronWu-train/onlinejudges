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
	multimap<int, int> mp;
	map<int, int> cnt;
	int n;
	while (cin >> n && n != 0) {
		auto it = mp.find(cnt[n]);	
		while (it != mp.end() && it->first == cnt[n] && it->second != n) it ++;
		if (it != mp.end()) mp.erase(it);
		cnt[n]++;
		mp.insert({cnt[n], n});
		int i = 0, k = mp.rbegin()->first;
		int h = INT_MAX;
		for (auto it = mp.end(); it != mp.begin() && prev(it)->first == k; --it) {
			i++;
			debug(prev(it)->first, prev(it)->second);
			h = min(prev(it)->second, h);
		}
		cout << k << " " << h << endl;
	}

	return 0;
}
