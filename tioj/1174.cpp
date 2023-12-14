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
	int n, m;
	cin >> n >> m;
	deque<int> a(n);
	deque<int> b(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	sort(AI(a));
	sort(AI(b));
	
	int k = INT_MAX;
	while (!a.empty() && !b.empty()) {
		if (a.front() < b.front()) {
			k = min(k, b.front() - a.front());
			a.pop_front();
		}
		else {
			k = min(k, a.front() - b.front());
			b.pop_front();
		}
	}
	cout << k << endl;

	return 0;
}
