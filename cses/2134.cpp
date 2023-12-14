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

struct SegTree{
	vector<int> arr;
	int n;
	void init(vector<int> v) {
		n = v.size();
		for (int i = 0; i < n; ++i) {
			arr[i + n] = v[i];
		}
		for (int i = n-1; i > 0; i--) {
			arr[i] = max(arr[i<<1], arr[i<<1^1]);
		}
	}
	void push(int i) {
		i /= 2;
		while (i) {
			arr[i] = max(arr[i<<1], arr[i<<1^1]);
			i /= 2;
		}
	}	
	int query(int l, int r) {
		l += n;
		r += n;
		int ret = INT_MIN;
		while (l < r) {
			if (l & 1) ret = max(ret, arr[l++]);
			if (r & 1) ret = max(ret, arr[--r]);
		}
		return ret;
	}	
	void modify(int i, int v) {
		i += n;
		arr[i] = v;
		push(i);
	}
}st;

const int MAXN = 1e4;
vector<int> adj[MAXN];
int dfnctr = 0;
int dfn[MAXN],dep[MAXN], sz[MAXN], fa[MAXN], tp[MAXN], hson[MAXN];
// hson = heavy son

void dfs(int i, int p) {
	sz[i] = 1;
	fa[i] = p;
	hson[i] = -1;
	for (auto &v : adj[i]) {
		if (v == p) continue;
		dep[v] = dep[i] + 1;
		dfs(v, i);
		sz[i] += sz[v];
		if (hson[i] == -1 || sz[hson[i]] < sz[v]) hson[i] = v;
	}
}

void link(int i, int p) {
	debug(i, p);
	tp[i] = p;
	dfn[i] = ++dfnctr;
	if (hson[i] != -1) link(hson[i], p);
	for (auto &v : adj[i]) {
		if (v == hson[i] || v == fa[i]) continue;
		link(v, v);
	}
}

int ask(int a, int b) {
	int ans = INT_MIN;
	while (tp[a] != tp[b]) {
		if (dep[tp[a]] < dep[tp[b]]) swap(a, b);
		ans = min(ans, st.query(dfn[tp[a]], dfn[a]+1));
		a = fa[tp[a]];
	}
	if(dfn[a] > dfn[b]) swap(a, b);
	ans = min(ans, st.query(dfn[a], dfn[b]));
	return ans;
}

signed main(){_
	int n, q;
	cin >> n >> q;
	vector<int> vec(n);
	for (auto &i : vec) cin >> i;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	dfs(1, -1);
	link(1, 1);
	debug("rrr");
	vector<int> arr2(n);
	for (int i = 0; i < n; ++i) {
		arr2[dfn[i+1]] = vec[i];
	}
	st.init(arr2);
	while(q--) {
		int tp, a, b;
		cin >> tp >> a >> b;
		if (tp == 1) {
			st.modify(dfn[a], b);
		}
		else {
			debug("rrr");
			cout << ask(a, b) << " ";
		}
	}
	cout << endl;

	return 0;
}
