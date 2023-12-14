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
#define int long long
#define pii pair<ll, ll>
#define first FF
#define second SS

const ll INF = 1e18;
signed main(){_
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> G(n+5, vector<ll>(n+5, INF));
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		G[a][b] = min(G[a][b], w);
		G[b][a] = min(G[b][a], w);
	}
	for (int i = 1; i <= n; ++i) G[i][i] = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}
	}
	while (q--){
		int a, b;
		cin >> a>>b;
		if (G[a][b] == INF) cout << "-1\n";
		else cout << G[a][b] << endl;
	}

	return 0;
}
