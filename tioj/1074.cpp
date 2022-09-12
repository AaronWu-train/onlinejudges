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
	int n;
	while (cin >> n && n) {
		vector<int> arr(n);
		int icount = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
			if (arr[i] == 1) icount++;
		}
		if (icount == n) {
			cout << "NO" << endl;
			continue;
		}
		vector <bool> visited(sum+5, 0);

		for (int i = 0; i < n; ++i) {
			int s = 0;
			for (int j = i; j < n; ++j) {
				s += arr[j];
				visited[s] = 1;
			}
		}
		bool flag = 1;
		for (int i = 1; i <= sum; ++i) {
			if (visited[i] == 0) {
				cout << "NO\n";
				flag = 0;
				break;	
			}
		}
		if (flag) {
			cout << "YES\n";
		}
	}

	return 0;
}
