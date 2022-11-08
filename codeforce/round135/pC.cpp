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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;
		map<int, bool> bhas;
		int sz[10] = {0};
		for (auto i : b) {
			bhas[i] = 1;
			sz[to_string(i).size()]++;	
		}	
		int ans = 0;		
		sort(AI(a), greater<int>());

		vector<int> ap;
		for (auto i : a){
			if(bhas[i]) {
				bhas[i] = 0;
			} else {
				ap.pb(to_string(i).size());
				ans++;
			}
		}
		map<int, int> bhp;
		for (auto i : bhas) {
			if (i.second) {
				if (i.first < 10) {
					bhp[to_string(i.first).size()]++;
					continue;
				}			
				ans++;
				bp.push_back(to_string(i.first).size());
			}
		}		
			
		cout << ans << endl;
	}

	return 0;
}
