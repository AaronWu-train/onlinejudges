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

int main(){_
	const double ce = 1e-9;
	string a, b;
	cin >> a >> b;
	stringstream ssa, ssb;
	ssa << a;
	ssb << b;
	int fa, fb;
	ssa >> fa;
	ssb >> fb;
	if (fa > fb) cout << a;
	else if (fb < fa) cout << b;
	else cout << max(a, b);
	cout << endl;
	return 0;
}
