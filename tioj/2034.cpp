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
	cin >> n;
	vector<int>arr(n,0);
	for (auto &i : arr) {
		cin >> i;
	}
	sort(AI(arr));
	bool tf = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] != arr[i-1]+1) {
			tf = 0;
			break;
		}
	}

	cout << arr[0] << " " << arr[n-1] << " " << (tf?"yes":"no") << endl;
	return 0;
}
