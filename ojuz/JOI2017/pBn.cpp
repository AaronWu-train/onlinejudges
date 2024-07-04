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
#define pb push_back

signed main() {_
	ll n, m, k; 
	cin >> n >> m >> k;
	ll a, b, c;
	cin >> a >> b >> c;
	vector<ll> fast;

	ll t; 
	cin >> t;

	for (ll i = 0; i < m; ++i) {
		ll s; cin >> s;
		fast.pb(s);
	}

	priority_queue<ll> pq;
	ll used = 0;
	ll bptr = 0;
	ll ccur = 1;
	ll cnt = -1;
	ll cccc = 0;

	while (used < k - m && ccur <= n) {
		if(bptr > m) break;
		int tleft = t - (b*(fast[bptr]-1) + c*(ccur-fast[bptr]));
		if (ccur == n) {
			debug("RRRR");
			if (tleft >= 0) cnt++;
			break;
		}
		if(tleft < 0) {
			if(ccur == fast[bptr]) {debug("LR"); break;}
			ccur = fast[bptr+1];
			bptr++;
			continue;
		}
		if (fast[bptr] == ccur) {
			int far = ccur + (tleft / a);
			far = min(n, far);
			if (far >= fast[bptr+1]) {
				cnt += fast[bptr+1] - fast[bptr];
				debug(fast[bptr], fast[bptr+1]-1);
				ccur = fast[bptr+1];
				bptr++;
			} else {
				cnt += far - ccur + 1;
				debug(ccur, far);
				ccur = far+1;
				if (ccur == fast[bptr+1]) bptr++;
			}
		} else {
			int far = ccur + (tleft / a);
			far = min(n, far);
			if (far >= fast[bptr+1]) {
				pq.push(fast[bptr+1] - ccur);
				debug(ccur, fast[bptr+1]-1 , "PQ", tleft);
				ccur = fast[bptr+1];
				bptr++;
			} else {
				pq.push(far - ccur + 1);
				debug(ccur, far, "PQ", tleft);
				ccur = far+1;
				if (ccur == fast[bptr+1]) bptr++;
				used++;
			}
		}
	}
	debug(fast[bptr]);
	bptr++;
	while(bptr < m) {
		ccur = fast[bptr];
		int tleft = t - (b*(fast[bptr]-1) + c*(ccur-fast[bptr]));
		if (ccur == n) {
			debug("RRRR");
			if (tleft >= 0) cnt++;
			break;
		}
		if(tleft < 0) {
			if(ccur == fast[bptr]) {debug("LR"); break;}
			ccur = fast[bptr+1];
			bptr++;
			continue;
		}
		if (fast[bptr] == ccur) {
			int far = ccur + (tleft / a);
			far = min(n, far);
			if (far >= fast[bptr+1]) {
				cnt += fast[bptr+1] - fast[bptr];
				debug(fast[bptr], fast[bptr+1]-1);
				ccur = fast[bptr+1];
				bptr++;
			} else {
				cnt += far - ccur + 1;
				debug(ccur, far);
				ccur = far+1;
				if (ccur == fast[bptr+1]) bptr++;
			}
		} 
		bptr++;
	}
	debug(k-m, cnt);
	for (int i = 0; i < k - m; ++i) {
		if (pq.empty()) break;
		cnt += pq.top();
		pq.pop();
	}
	cout << cnt << endl;
}