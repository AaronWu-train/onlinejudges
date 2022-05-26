#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#define ff first
#define ss second
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif

int main(){
	int n,d;
	cin >> n >> d;
	bool have = 1;
	int x;
	int ans = 0;
	cin >> x;
	for(int i = 2; i<=n; ++i) {
		int y;
		cin >> y;
		if(have && y >= x+d) {
			ans += y-x;
			x=y;
			debug(x);
			have = 0;
		}else if (!have && y <= x-d) {
			x=y;
			have = 1;
		}
	}
	cout << ans << endl;

	return 0;
}
