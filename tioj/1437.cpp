#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

signed main(){_
	int w;
	cin >> w;
	int mx = -1, cmx = -1;
	for(int i = 0; i < w; ++i) {
		for (int j = 0; j < w; ++j) {
			int a; cin >> a;
			if (a > mx) cout << "(" << j << ","<<i<<")\n";
			cmx = max(cmx, a);
		}
		mx = cmx;
		cmx = -1;
	}

	return 0;
}
