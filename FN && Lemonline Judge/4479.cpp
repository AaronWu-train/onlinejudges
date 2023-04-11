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

signed main(){
	char n;
	ll x = 0, y = 0;
	ll sx = 0, sy = 0, s = 0;
	bool is_x = 1, is_neq = 0;
	while ((n = getchar())!= EOF) {
		debug(n);
		if (n == ' ' || n == '\n') continue;
		if (n == '(') {
			is_x = 1;
			is_neq = 0;
			x = 0, y = 0, s++;
		}	
		else if (n == ',') {
			is_x = 0;
			if (is_neq) x = -x;
			sx += x;
			is_neq = 0;
			
		} 
		else if (n == ')') {
			is_x = 1;
			if (is_neq) y = -y;
			sy += y;
			is_neq = 0;
		}
		else if (n == '-') {
			is_neq = 1;
		}
		else if (n >= '0' && n <= '9') {
			if (is_x) {
				x *= 10;
				x += n-'0';
			} else {
				y *= 10;
				y += n-'0';
			}
		}
	}
	debug(sx,sy,s);
	printf("(%.3f,%.3f)", (double)sx/s, (double)sy/s);

	return 0;
}
