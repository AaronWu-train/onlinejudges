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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>arr(n);
        for (auto &i : arr) cin >> i;
        vector<ll>dp(n,0);
        dp[0] = 0;
        dp[1] = abs(arr[1]-arr[0]);
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]), dp[i-2] + abs(arr[i] - arr[i-2]));
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}
