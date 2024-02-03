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
#define pii pair<int, int>

signed main(){_
	int n,k;
	cin >> n >> k;
	vector<int> adj[2*k+5];
	vector<int> deg(2*k+5);
	for (int i = 0; i < n; ++i) {
		int a, b;cin >> a >> b;
		b += k;
		adj[a].pb(b);
		adj[b].pb(a);
		deg[a]++;
	   	deg[b]++;
	}
	OI(AI(deg));
	set<pii, greater<pii>> mp;
	for (int i = 1; i <= 2*k; ++i) {
		mp.insert(make_pair(deg[i], i));
	}
	vector<int> vis(2*k+5);
	vector<int> ansa;
	vector<int> ansb;
	while (mp.begin()->first > 0) {
		auto [w, i] = *mp.begin();
		debug(i);
		if (i <= k) ansa.pb(i);
		else ansb.pb(i-k);
		vis[i] = 0;
		mp.erase(mp.begin());
		for (auto &j : adj[i]) {
			if (!vis[j]) {
				mp.erase(mp.find(make_pair(deg[j], j)));
				deg[j]--;
				mp.insert(make_pair(deg[j], j));
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
