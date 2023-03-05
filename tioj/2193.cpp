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

signed main(){_
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i;
	stable_sort(AI(arr),[](ll a, ll b){
			int ka = 0, kb = 0;
			for (int i = 1; i <= 2048; i <<= 1) {
				if (a & i) ka++;
				if (b & i) kb++;
			}
			return ka < kb;
			});
	for (auto &i : arr) cout << i << " \n"[&i == &arr.back()];
	return 0;
}
