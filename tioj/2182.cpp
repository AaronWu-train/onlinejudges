#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){_
	int m, n;
	cin >> m >> n;
	int arr[m][n];
	for (auto &i : arr) for (auto &j : i) cin >> j;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int k = 0;
			if (i > 0) k = max(k, arr[i-1][j]);
			if (j > 0) k = max(k, arr[i][j-1]);
			arr[i][j] += k;
		}
	}
	int ans = -105;
	for (int i = 0; i < m; i++) ans = max(arr[i][n-1], ans);
	for (int j = 0; j < n; ++j) ans = max(arr[m-1][j], ans);
	cout << ans << endl;
	return 0;
}
