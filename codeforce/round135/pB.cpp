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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == 2) {
			cout << "1 2\n"; continue;
		} 
		if (n == 3) {
			cout << "2 1 3\n"; continue;
		}
		if (n & 1) {
			for (int i = n-4; i >= 2;--i) {
				cout << i << " ";
			}
			cout << 1 << " ";
			for (int i = n - 3; i <= n;++i) {
				cout << i << " ";
			}	
			cout << endl;
		}else{
			for (int i = n - 2; i >= 1; --i) {
				cout << i << " ";
			}
			cout << n-1 << " " << n << endl;
		}
	}

	return 0;
}
