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
const ll mxn = 2e5+5;
ll sz[mxn], hefa[mxn], dep[mxn];
vector<ll> adj[mxn];
ll ans = 0;
ll dz = 0;
ll n, k;
const ll mod = 998244353;

ll mpow(ll a, ll x) {
	ll r= 1;
	for(int i=1; i<=x; i <<= 1) {
		if (i & x) r = r * a % mod;
		a = a*a%mod;
	}
	return r;
}

int dfs1(int i, int fa) {
	sz[i] = 1;
	dep[i] = dep[fa] + 1;
	hefa[i] = max(dep[i] - 2, 0ll);
	for (auto &j : adj[i]) {
		if (j == fa) continue;
		sz[i] += dfs1(j, i);
	}	
	return sz[i];
}

void dfs2(int i, int fa, int hh) {
	ans += mpow( ((n-sz[i])*sz[i]%mod) , k);
	ans -= hh * mpow(sz[i],k) % mod;
	ans = (ans % mod+ mod) % mod;
	ll gg = mpow(n - sz[i], k);
	dz++;
	for (auto &j : adj[i]) {
		if (j == fa) continue;
		dfs2(j, i, gg);
		gg += mpow(sz[j], k);
		gg %= mod;
	}
}


signed main(){_
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	dfs1(1, 1);
	dfs2(1, 1, 0);
	cout << ans*mpow(2,k)%mod << endl;
	return 0;
}
