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
    int m, n;
    cin >> m >> n;
    while (m--) {
        vector<int>arr(n, 0);
        int sum = 0;
        for (auto &i : arr) {
            cin >> i;
            i*=2;
            sum += i;
        }
        vector<int> dp(sum+5);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if ( j >= arr[i] ) dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
//        OI(AI(dp));
        if (dp[sum/2]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
