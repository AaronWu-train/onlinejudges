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

struct BIT{
	vector<int> arr;
	int n;
	BIT(int _n) {
		n = _n;
		arr.resize(n);
	}	
	void modify(int i, int v) {
		for (; i <= n; i += i&(-i)) {
			debug(i);
			arr[i] += v;
		}
	}

	int query(int i) {
		ll ans = 0;
		for (; i > 0; i -= i&(-i)){
			debug(i);
			ans += arr[i];
		}
		return ans;
	}
};

const int nn = 2e5+5;
vector<int> adj[nn];
int l[nn], r[nn];
int cnt = 1;
void dfs(int i, int fa) {
	debug(i);
	l[i] = cnt++;
	for (auto &j : adj[i]) {
		if (j == fa) continue;
		dfs(j, i);
	}
	r[i] = cnt++;
}

signed main(){_
	int n, q;
	cin >> n >> q;
	vector<int> arr(n+1);
	BIT bit(2*n+5);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n-1; ++i) {
		int a,b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1);
	debug("EEE");
	for (int i = 1; i <= n; ++i){
		bit.modify(l[i], arr[i]);
		bit.modify(r[i], -arr[i]);
	}
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int s, x; cin >> s >> x;
			
			bit.modify(l[s], -arr[s]);
			bit.modify(r[s], arr[s]);

			arr[s] = x;

			bit.modify(l[s], arr[s]);
			bit.modify(r[s], -arr[s]);
		}
		else {
			int s; cin >> s;
			cout << bit.query(l[s]) << endl;
		}
	}

	return 0;
}
