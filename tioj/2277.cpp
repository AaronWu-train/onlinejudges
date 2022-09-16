#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#define pii pair<int, int>
#define pb push_back
#define FF first
#define SS second
#ifdef AaW
#define debug(args...) LKJ("[" #args "]",args)
template<class I> void LKJ(I&&x) {cerr << x << endl;}
template<class I, class ...T> void LKJ(I&&x, T&&...t) {cerr << x << " ", LKJ(t...);}
template<class I> void OI(I a, I b){while (a != b) cerr << *a << " \n"[next(a)==b], a++;}
#else 
#define debug(...) 0
#define OI(...) 0
#endif
struct node{
	int id = 0;
	int l = 0, r = 0, p = 0;
};

struct DSU {
	vector <int> fa;
	int n;
	int size;
	void init(int _n) {
		n = _n;
		fa.resize(n+5);
		size = n;
		for (int i = 0; i <n+5; ++i) {
			fa[i] = i;
		}
	}
	int query(int x) {
		if ( x == fa[x] ) return x;
		fa[x] = query(fa[x]);
		return fa[x];
	}
	void modify(int a, int b) {
		a = query(a);
		b = query(b);
		if (a == b) return;
		fa[b] = a;
		size--;
	}
}dsu;
vector<node> tree;

void dfs(int id, vector<int>&vec, int mode) {
	if (mode == 1) vec.pb(id);
	if (tree[id].l) dfs(tree[id].l, vec, mode);
	if (mode == 2) vec.pb(id);
	if (tree[id].r) dfs(tree[id].r, vec, mode);
	if (mode == 3) vec.pb(id);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q;
	cin >> n >> q;
	tree.resize(n+5);
	tree[1].id = 1;
	tree[1].p = 1;
	for (int i = 2; i <= n; ++i) {
		int pp, tt;
		cin>>pp>>tt;
		tree[i].p = pp;
		tree[i].id = i;
		if (tt) {
			tree[pp].r = i;
		} else {
			tree[pp].l = i;
		}
	}
	vector<int> fr, mid, bk;
	dfs(1, fr, 1);
	dfs(1, mid, 2);
	dfs(1, bk, 3);
	
	dsu.init(n);
	for(int i = 0; i < n/2; ++i) {
		dsu.modify(fr[i], fr[n-i-1]);
		dsu.modify(mid[i], mid[n-i-1]);
		dsu.modify(bk[i], bk[n-i-1]);
	} 
	cout << dsu.size << endl;
	for (int i = 0;i < q;++i) {
		int a, b;
		cin >> a >> b;
		dsu.modify(a, b);
		cout << dsu.size << endl;
	}
	return 0;
}



