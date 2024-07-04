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

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
		int a = min(red, blue);
		int b = max(red, blue);
		int ans = 0;
		for (int i = 1; i < 22; ++i) {
			if (a < i) break;
			a -= i;
			ans++;
			swap(a, b);
		}
		int aa = max(red, blue);
		int bb = min(red, blue);
		int ans2 = 0;
		for (int i = 1; i < 22; ++i) {
			if (aa < i) break;
			aa -= i;
			ans2++;
			swap(aa, bb);
		}
		return max(ans, ans2);
    }
};


