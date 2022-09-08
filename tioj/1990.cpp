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

template<class T> 
void mswap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}



int main(){_
	int n, m;
	cin >> m >> n;
	string ARR[m][n];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> ARR[i][j];
		}
	}
	vector<int>x(m+5, 0);
	for (int i = 1; i <= m; ++i) {
		x[i] = i-1;
	}
	vector<int>y(n+5, 0);
	for (int j = 1; j <= n; ++j) {
		y[j] = j-1;
	}
	int p;
	cin >> p;
	while(p--) {
		char tp;
		cin >> tp;
		if (tp == 'S') {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			mswap(ARR[x[a]][y[b]], ARR[x[c]][y[d]]);
		} else if ( tp == 'R') {
			int a, b;
			cin >> a >> b;
			mswap(x[a], x[b]);
		} else if (tp == 'C') {
			int a, b;
			cin >> a >> b;
			mswap(y[a], y[b]);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ARR[x[i]][y[j]] << " ";
		}
		cout << endl;
	}

	return 0;
}
