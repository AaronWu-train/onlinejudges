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
	vector<vector<int>> g(n, vector<int>(m, 0));
	vector<vector<int>> pre(n, vector<int>(m, 0));
	int ans = 0;
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char temp; cin >> temp;
			g[i][j] = (temp == '#');
			pre[i][j] = pre[i][j-1] + g[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!g[i][j]) continue;
			int l = j - 1, r = j + 1, k = i + 1;
			bool flag = 1;
			while (l >= 0 && r < m && k < n) {
				if (!g[k][l] || !g[k][r]) {
					// cerr << "RRR";
					// debug(i, j, l, r, k);

					//debug(l, r, k);
					break;
				}
				if (pre[k][r] - pre[k][l] > 1){
					break;
				}	
				l -= 1;
				r += 1;
				k += 1;
			}
			if (!flag) continue;
			r -= 2;
			l += 2;
			while (k < n && r >= l) {
				if (!g[k][l] || !g[k][r] || pre[k][r] - pre[k][l] > 1){
					flag = 0;
			//		cerr << "KKK" << endl;
			//		debug(l, r, k, pre[k][r], pre[k][l]);
					break;
				}
				r -= 1;
				l += 1;
				k += 1;
			}
			//debug(flag);
			if (l <= r || k < i + 2) flag = 0;
			ans += flag;
			//if (flag) debug(i, j, l, r, k);
			//cerr << "\n\n";
		}
	}
	cout << ans << endl;



	return 0;
}
