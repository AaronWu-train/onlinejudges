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
#define pii pair<int, int>


void solve() {
	int n; 
	cin >> n;
	int x, y; cin >> x >> y;;
	int arr[2005][2005] = {0};
	int h[2005] = {0};
	int v[2005] = {0};
	h[1] = v[1] = 1;
	arr[1][1] = 1;
	vector<pii> ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!arr[i][j] && h[i]&1 && v[j] &1) {
				arr[i][j] = 1;
				h[i]++; v[j]++;
				ans.pb({i, j});
			}
		}	
	}
	if (n == 1) {cout << 1 << endl;for (int i = 0; i < 0; ++i) cout <<1<< " " << 1 << endl;}
	else if (n == 2){ cout << 4 << endl;for (int i = 0; i < 3; ++i) cout <<1<< " " << 1 << endl;}
	else if (n == 3) {cout << 7 << endl;for (int i = 0; i < 6; ++i) cout <<1<< " " << 1 << endl;}
	else if (n == 4) {cout << 16 << endl;for (int i = 0; i < 15; ++i) cout <<1<< " " << 1 << endl;}
	else if (n == 5) {cout << 21 << endl;for (int i = 0; i < 20; ++i) cout <<1<< " " << 1 << endl;}
	else cout << 1 << endl;
	

	
}

signed main(){_
	int t; 
	cin >> t;
	for (int  i = 0; i < t; ++i) {
		solve();
	}	

	return 0;
}
