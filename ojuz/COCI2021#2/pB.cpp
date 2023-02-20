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
struct DSU{
	int n;
	vector<int> arr;
	void init(int _n) {
		n = _n;
		arr.clear();
		arr.resize(n+1);
		for (int i = 0; i <= n; ++i) {
			arr[i] = i;
		}
	}
	int query(int a) {
		if (arr[a] == a) return a;
		arr[a] = query(arr[a]);
		return arr[a];
	}
	void modify(int a, int b) {
		a = query(a);
		b = query(b);
		arr[a] = b;
	}
}djs;


signed main(){_
	int n, m, q;
	cin >> n >> m >> q;
	djs.init(n);
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			int temp;
			cin >> temp;
			djs.modify(temp, j);
		}
	}	
	for (int i = 0; i < q; ++i){
		int a, b;
		cin >> a >> b;
		if (djs.query(a) == djs.query(b)) {
			cout << "DA\n";
		} else {
			cout << "NE\n";
		}
	}

	return 0;
}
