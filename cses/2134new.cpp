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
vector<vector<int>> adj;
vector<int> fff, v2;
vector<int> treetop, dep, sz, hson, fa;
int timer=0;
vector<int> pos;

struct SegmentTree{
	vector<int> st;
	int n;
	void init(int x, const vector<int> &arr) {
		n = x;
		st.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			st[i+n] = arr[i];	
		}
		for (int i = n-1; i > 0; i--) {
			st[i] = max(st[i*2], st[i*2+1]);
		}
	}

	void modify(int p, int x) {
    	for(st[p+=n] = x; p > 1; p>>=1)
		   	st[p>>1] = max(st[p],st[p^1]);
	}

	int query(int l, int r) { // [l,r)
	    int res = -1e9;
 	   	for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
 	       if(l&1) res = max(res, st[l++]);
 	       if(r&1) res = max(res, st[--r]);
  		}
    	return res;
	}
}seg;

void dfs(int i, int f) {
	sz[i] = 1;
	fa[i] = f;
	hson[i] = -1;
	for (auto &j : adj[i]) {
		if (j == f) continue;
		dep[j] = dep[i] + 1;
		dfs(j, i);
		sz[i] += sz[j];
		if (hson[i] == -1 || sz[hson[i]] < sz[j]) hson[i] = j;
	}
}

void link(int i, int top) {
	treetop[i]=top;
	pos[i] = ++timer;
	v2[timer] = fff[i];
	if (hson[i] != -1) link(hson[i], top);
	for (auto &j : adj[i]) {
		if (j != fa[i] && j != hson[i]) link(j, j);
	}
}

int jump(int a, int b) {
	int ans = 0;
	while(treetop[a] != treetop[b]) {
		if (dep[treetop[a]] < dep[treetop[b]]) swap(a, b);
		// segment tree ask from pos[a] to pos[treetop[a]]
		ans = max(ans, seg.query(pos[treetop[a]], pos[a]+1));
		a = fa[treetop[a]];
	}	
	if (pos[a] > pos[b]) swap(a, b);
	// segment tree ask from pos[a] to pos[b]
	ans = max(ans, seg.query(pos[a], pos[b]+1));
	return ans;
}

signed main(){_
	int n, q;
	cin >> n >> q;
	fa.resize(n+5);
	treetop.resize(n+5);
	dep.resize(n+5);
	sz.resize(n+5);
	hson.resize(n+5);
	pos.resize(n+5);
	adj.resize(n+5);
	fff.resize(n+5);
	v2.resize(n+5);
	for (int i = 1; i <= n; ++i) cin >> fff[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	fa[1] = 1;
	dfs(1, 1);
	link(1, 1);	
	seg.init(n+1, v2);
	for(int i = 0; i < q; ++i) {
		int tp, a, b;
		cin >> tp >> a >> b;
		if (tp == 1) {
			seg.modify(pos[a], b);
		} else {
			cout << jump(a, b) << " ";
		}
	}
	cout << endl;

	return 0;
}
