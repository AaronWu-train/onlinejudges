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
#define int unsigned

struct Mat {
    // n*n 方陣 
    vector<vector<int>> A;
    int n;
    Mat(int _n){
        n=_n;
		for (int i = 0; i < n; ++i) {
			A.pb(vector<int>(n));
		}
    }
};

Mat operator *(const Mat &m1, const Mat &m2) {
    assert(m1.n == m2.n);
    int n = m1.n;
    Mat ret(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret.A[i][j] += (m1.A[i][k] * m2.A[k][j]);
            }
        }
    }
    return ret;
}

Mat pow (Mat a, int n) {
    Mat ans(a.n);
    for (int i = 0; i < a.n; ++i) {
        ans.A[i][i]=1;
    } // 斜角化
    for (int i=1;i<=n;i<<=1) {
        if (n&i) ans = ans * a;
        a = a * a;
    }
    return ans;
}

signed main(){_
	signed n;
	int	a, b, x, y;
	while (cin >> n) {
		if (n < 0) break;
		cin >> a >> b >> x >> y;	
		Mat K(2);
		K.A = {{y, x},{1,0}};
		Mat R(2);
		R.A = {{b, 0}, {a, 0}};
		if (n == 0) cout << a << endl;
		else {
			cout << (pow(K, n-1) * R).A[0][0] << endl;
		}
	}


	return 0;
}
