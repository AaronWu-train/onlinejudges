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
const ll maxn = 1e6+5;
vector<bool> isPrime(maxn, 1);

struct BIT{
	vector<int> arr;
	void init (int n) {
		arr.clear();
		arr.resize(n+5);
	}
};


signed main(){_
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 2; i < maxn; ++i) {
		if (!isPrime[i]) continue;
		for (ll j = i; i * j < maxn; ++j){
			isPrime[i * j] = 0;	
		}
	}
	
	return 0;
}
