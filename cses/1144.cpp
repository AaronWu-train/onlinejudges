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
#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T> using RBT = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


signed main(){_
	RBT<pair<int, int>> tr;
	int n, q;
	cin >> n >> q;
	vector<int> arr(n+5);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		tr.insert({arr[i], i});
	}
	while(q--) {
		char tp;
		cin >> tp;
		if (tp == '!') {
			int k, x;
			cin >> k >> x;
			tr.erase({arr[k], k});
			arr[k] = x;
			tr.insert({arr[k], k});
		}
		else if (tp == '?') {
			int a, b;
			cin >> a >> b;
			cout << tr.order_of_key({b, 1e9+7}) - tr.order_of_key({a-1, 1e9+7}) << endl;
		}
	}	


	return 0;
}
