#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
	int n;
	vector<int> arr;
	void modify(int pos, int x) {
		for (int i = pos; i <= n; i+=i&(-i)) {
			arr[i] += x;
		}
	}

	int query(int i) {
		int ret = 0;
		for (; i > 0; i-=i&(-i)) {
			ret += arr[i];
		}
		return ret;
	}

	void init(int _n) {
		n = _n;
		arr.resize(n+5, 0);	
	}
}bit;
vector<int> l;
vector<int> r;
int temp = 0;
void dfs(int i, vector<vector<int>>& adj,vector<int>& value, vector<bool> &visited) {
	l[i] = ++temp;
	visited[i] = 1;
	for (auto c : adj[i]) {
		if (!visited[c]) {
			dfs(c, adj, value, visited);
		}
	}	
	r[i] = ++temp;
	bit.modify(r[i], value[i]);
}

signed main(){_
	int n, q;
	cin >> n >> q;
	vector <int> arr(n+5);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	vector< vector<int> > adj(n+5);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bit.init(n*2);
	vector<bool>visited(n+5);
	l.resize(n+5);
	r.resize(n+5);
	dfs(1, adj, arr, visited);
	OI(AI(l));
	OI(AI(r));
	while(q--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int pos, x;
			cin >> pos >> x;
			bit.modify(r[pos], x - arr[pos]);
			arr[pos] = x;
		}
		else {
			int h;
			cin >> h;
			//debug(l[h],bit.query(l[h]));
			//debug(r[h],bit.query(r[h]));

			cout << bit.query(r[h]) - bit.query(l[h]) << endl;
		}
	}	


	return 0;
}
