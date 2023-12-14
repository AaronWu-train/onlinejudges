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
const int mxn = sqrt(1e3) + 1;
bool np[mxn];
#define pii pair<int, int>

signed main(){_
	int n;
	cin >> n;
	vector<int> primes;
	debug("Eee");
	np[0] = np [1] = 1;
	for (int i = 2; i < mxn; ++i) {
		if (!np[i]) primes.pb(i);
		for (int j = i + i; j < mxn; j+=i) {
			np[j] = 1;
		}
	}
	vector<int> a(n+1);
	vector<int> b(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	vector<vector<pii>> adj(n+primes.size()+1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < primes.size(); ++j) {
			if (a[i] % primes[j] == 0) {
				adj[i].pb({j + n + 1, 0});
				adj[j + n + 1].pb({i, b[i]});
				debug(a[i], primes[j]);
				while (a[i] % primes[j] == 0 && a[i])  a[i] /= primes[j];
			}
		}
		if (a[i] > 1) {
			primes.pb(a[i]);
			int j = primes.size() - 1;
			adj.pb(vector<pii>());
			adj[i].pb({j + n + 1, 0});
			adj[j + n + 1].pb({i, b[i]});
		}
	}
	int s;
	cin >> s;
	for (int j = 0; j < primes.size(); ++j) {
		if (s % primes[j] == 0) {
			adj[0].pb({j + n + 1, 0});
			while (s && s % primes[j] == 0) s /= primes[j];
		}
	}
	int nn = adj.size();
	vector<ll> dis(nn+5, LLONG_MAX);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,0});
	dis[0] = 0;

	vector<bool> visited(nn+5);
	while (pq.size()) {
		auto [ww, u] = pq.top();
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		for (auto [v, w]:adj[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	for (int i = 1; i <= n; ++i)  {
		ll mx = LLONG_MAX;
		for (auto &[j,w] : adj[i]) {
			mx = min(mx, dis[j]);	
		}
		if (mx == LLONG_MAX) cout << -1 << " ";
		else cout << mx << " ";
	}
	cout<<endl;

	return 0;
}
