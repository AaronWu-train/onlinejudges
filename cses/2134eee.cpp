#include<bits/stdc++.h>
#define pb push_back
#define sz(x) (int)(x.size()
#define all(x) x.begin(), x.end()
#define int long long 
#define pii pair<int, int>
#define inf 0x3f3f3f3f
#define ar(x) array<int, (x)>
#define mod 1000000007
#define io ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
const int mxN = 2e5 + 5;
 
int n, q, tk, val[mxN], t[mxN], sz[mxN], fa[mxN], hson[mxN], tp[mxN], dep[mxN], dfn[mxN], seg[mxN * 4];
// hson -> heavy son
// tp -> top of chain
vector<int> g[mxN];
 
void dfs(int u, int p) { 
	sz[u] = 1;
	fa[u] = p;
	hson[u] = -1;
	if(p != -1) dep[u] = dep[p] + 1;
	for (int v : g[u]) {
		if(v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if(hson[u] == -1 || sz[v] > sz[hson[u]]) hson[u] = v;
	}
}
 
void link(int u, int p) {
	tp[u] = p;
	dfn[u] = ++tk;
	val[tk] = t[u];
	if(hson[u] != -1) link(hson[u], p);
	for(int v : g[u]) {
		if(v == fa[u] || v == hson[u]) continue;
		link(v, v);
	}
}
 
void build(int l = 1, int r = n, int x = 1) {
	if(l == r) {
		seg[x] = val[l];
		return;
	}
	int mid = l+r>>1;
	build(l, mid, x<<1); build(mid+1, r, x<<1|1);
	seg[x] = max(seg[x<<1], seg[x<<1|1]);
}
 
void modify(int pos, int v, int l = 1, int r = n, int x = 1) {
	if(l == r) {
		seg[x] = v;
		return;
	}
	int mid = l+r>>1;
	if(pos <= mid) modify(pos, v, l, mid, x<<1);
	else modify(pos, v, mid+1, r, x<<1|1);
	seg[x] = max(seg[x<<1], seg[x<<1|1]);
}
 
int ask(int a, int b, int l = 1, int r = n, int x = 1) {
	if(a <= l and r <= b) return seg[x];
	int mid = l+r>>1, res = 0;
	if(a <= mid) res = ask(a, b, l, mid, x<<1);
	if(b > mid) res = max(res, ask(a, b, mid+1, r, x<<1|1));
	return res;
}
 
int query(int a, int b) {
	int ans = 0;
	while(tp[a] != tp[b]) {
		if(dep[tp[a]] < dep[tp[b]]) swap(a, b);
		ans = max(ans, ask(dfn[tp[a]], dfn[a]));
		a = fa[tp[a]];
	}
	if(dfn[a] > dfn[b]) swap(a, b);
	ans = max(ans, ask(dfn[a], dfn[b]));
	return ans;
}
 
signed main(){
	io;
	cin >> n >> q;
	int a, b, s;
	for(int i = 1; i <= n; i++) 
		cin >> t[i];
	for(int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		g[a].pb(b); g[b].pb(a);
	}
	dfs(1, -1);
	link(1, 1);
	build();
	while(q--) {
		cin >> s >> a >> b;
		if(s == 1) modify(dfn[a], b);
		else cout << query(a, b) << '\n';
	}
}
