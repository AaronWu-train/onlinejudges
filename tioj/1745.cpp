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
#define int long long
signed main(){_
	int n;
	int a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	int p[n+5];
	p[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		p[i] += p[i-1];
	}
	ll d[n+5];
	ll bb[n+5];
	ll aa[n+5];
	d[0]= bb[0] = aa[0] = 0;
	deque<int> mono;
	mono.push_back(0);
	for (int i = 1; i <= n; ++i) {
		while (mono.size() >= 2 && 
				p[i]*aa[mono[0]] + bb[mono[0]] <= p[i]*aa[mono[1]] + bb[mono[1]]) {
			debug(mono.front());
			mono.pop_front();
		}
		d[i] = p[i]*aa[mono[0]] + bb[mono[0]] + a*p[i]*p[i] + b*p[i] + c;
		aa[i] = -2 * a * p[i];
		bb[i] = d[i] -b*p[i] + a*p[i]*p[i];
		debug(i, d[i], aa[i], bb[i]);
#define mmmm mono[ mono.size() - 2]
#define nnnn mono[ mono.size() - 1]
		while (mono.size() >= 2 &&
				(bb[mmmm] - bb[i]) * (aa[nnnn] - aa[mmmm]) <= (bb[mmmm] - bb[nnnn])*(aa[i] - aa[mmmm])) {
			debug(mono.back());
			mono.pop_back();
		}
		mono.push_back(i);
	}
	cout << d[n] << endl; 

	return 0;
}

