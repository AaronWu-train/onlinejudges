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
const int xxn = 2e5+5;

vector<ll> l, r;
vector<int> adj[xxn];
int anc[xxn][21];
int dep[xxn];

void dfs(int i, int fa, int& cnt) {
	debug(i);
	l[i] = cnt++;
	dep[i] = dep[fa] + 1;
	anc[i][0]=fa;
	for (int j = 1; j <= 20; ++j) {
		anc[i][j] = anc[anc[i][j-1]][j-1];
	}
	for (auto &j : adj[i]) {
		if (j != fa) dfs(j, i, cnt);
	}
	r[i] = cnt++;
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 20; i >= 0; --i) {
		if (dep[anc[a][i]] >= dep[b]) a = anc[a][i];
	}
	debug(a, b);
	if (a == b) return a;
	for (int i = 20; i >= 0; --i) {
		if (anc[a][i] != anc[b][i]) {
			debug(anc[a][i]);
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}


struct BIT{
	vector<ll> a;
	int n;
	void init(int _n) {
		n = _n;
		a.resize(n+5);
	}
	void modify(ll i, ll v) {
		for (; i<=n;i+=(i&-i)){
			a[i] += v;
		}
	}
	ll query(int i) {
		ll re = 0;
		for (;i > 0; i -=(i&-i)) {
			re += a[i];	
		}
		return re;
	}
}bit2, bit3;

signed main(){_
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		adj[a].pb(i);
		adj[i].pb(a);
	}
	for (int i = 0; i <= 20; ++i) anc[1][i] = 1;
	vector<ll> val(n+2);
	bit2.init(2*n+5);
	bit3.init(2*n+5);
	l.resize(n+5);
	r.resize(n+5);
	int cnt = 1;	
	dfs(1, 1, cnt);
	debug("t");
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int u,c;
			cin >> u >> c;
			bit2.modify(l[u], c);
			bit2.modify(r[u], -c);
			bit3.modify(r[u], c);
			val[u] += c;
		} 
		if (tp == 2) {
			int u, v;
			cin >> u >> v;
			int k = lca(u, v);
			debug(k);
			cout << bit2.query(l[u]) - bit2.query(l[k]) + bit2.query(l[v]) - bit2.query(l[k])+ val[k] << endl;;
		}	
		if ( tp == 3) {
			int u; cin >> u;
			cout << bit3.query(r[u]) - bit3.query(l[u]) << endl;
		}
	}	

	return 0;
}
