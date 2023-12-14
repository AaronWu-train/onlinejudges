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
	int curid = 0, sum = 0, f = 1;
	bool out[n] = {0};
	for (int t = 0; t < m; ++t) {
		char c;
		cin >> c;
		switch (c) {
			case 'A':
				sum = 0;
				break;
			case '4':
				f *= -1;
				break;
			case '5':
				int b;
				cin >> b;
				curid = b-f;
				break;
			case 't':
				sum -= 10;
				break;
			case 'j':
				break;
			case 'q':
				sum -= 20;
				break;
			case 'k':
				sum = 99;
				break;
			default:
				int sid = c - '0';
				if (sum + sid > 99) {
					cout << curid << endl;
					//cout << curid << "死了哈哈" << endl;
					out[curid] = 1;
				} else {
					sum += sid;

				}
		}
		curid += f;
		curid = (curid + n) % n;	
		while (out[curid]) {
			curid += f;
			curid = (curid + n) % n;	
		}
	}
//	cout << "他們還活著欸：" << endl;
	for (int i = 0; i < n; ++i) {
		if (out[i] == 0) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
