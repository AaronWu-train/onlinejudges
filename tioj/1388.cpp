#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main() {_
    int n;
    while (cin >> n) {
        vector<ll> arr(n);
        vector<vector<ll>> dp(n+5, vector<ll>(n+5, 0));
        for (auto &i : arr) cin >> i;
        for (int i = 0; i < n; ++i) dp[i][i] = arr[i];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; i + j < n; ++j) {
                if ((i+1)%2) { // len = i+1 = 奇數
                    for (int m = j; m < i+j; ++m) {
                        ll lm = dp[j][m] * dp[m+1][j+i];
                        dp[j][j+i] = max(lm, dp[j][j+i]);
                    }
                }
                else {
                    for (int m = j; m < i+j; ++m) {
                        ll lm = dp[j][m] + dp[m+1][j+i];
                        dp[j][j+i] = max(lm, dp[j][j+i]);
                    }
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
