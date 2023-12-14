#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define AI(x) begin(x),end(x)
#define endl '\n'
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

signed main() {_
	ll n, m, k; 
	cin >> n >> m >> k;
	ll a, b, c;
	cin >> a >> b >> c;
	map<int,bool> fast;

	ll t; cin >> t;

	for (ll i = 0; i < m; ++i) {
		ll s; cin >> s;
		fast[s] = 1;
	}

	priority_queue<ll> pq;
	ll cnt = 0;
	ll lb = 0;
	map<int,bool> ceed;
	for (ll i = 1; i < n; ++i) {
		if (fast[i+1]) lb = i;
		if (i * a <= t || lb*b + (i-lb)*a <= t){
			cnt++;
			continue;
		} 
		if (ceed[i]) continue;
		ll cc = 0;
		for (ll j = i; j < n; ++j) {
			if (fast[j+1]) break;
			if (lb*b + (i-lb)*c + (j-i)*a > t) break;
			cc++;
			ceed[j]=1;
		}
		pq.push(cc);
	}

	for (ll i = 0; i < k - m; ++i) {
		if (pq.empty()) break;
		cnt += pq.top();
		pq.pop();
	}
	cout << cnt << endl;
}