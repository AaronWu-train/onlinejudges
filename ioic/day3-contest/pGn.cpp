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
	ll n, k;
	cin >> n >> k;
	vector<int> ga[n+1];
	vector<int> gb[n+1];
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		ga[a].pb(b);
		gb[b].pb(a);
	}
	vector<int> ansa;
	vector<int> ansb;
	bool visa[n+1] = {0};
	bool visb[n+1] = {0};
	for (int i = 1; i <= n; ++i) {
		if (!visa[i]){
			queue<int> bfs;
			bfs.push(i);
			visa[i] = 1;
			vector<int> ka, kb;
			while(!bfs.empty()){
				auto x = bfs.front();
				bfs.pop();
				if (x <= n) {
					// x === a
					ka.pb(x);
					for (auto &j : ga[x]) {
						if (!visb[j]){
							bfs.push(j+n);
							visb[j] = 1;
						}
					}	
				} else {
					x -= n;
					kb.pb(x);
					for (auto &j : gb[x]) {
						if (!visa[j]){
							bfs.push(j);
							visa[j] = 1;
						}
					}
				}	
			}
			if (ka.size() < kb.size()) {
				for (auto &i : ka) ansa.pb(i);
			} else {

				for (auto &i : kb) ansb.pb(i);
			}

		}
	}
	sort(AI(ansa)); 
	sort(AI(ansb));
	cout << ansa.size() << " " << ansb.size() << endl;
	for (auto &i: ansa) cout << i << " "; cout << endl;
	for (auto &i: ansb) cout << i << " "; cout << endl;

	

	
	return 0;
}
