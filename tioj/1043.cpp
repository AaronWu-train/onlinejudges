#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long int
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
    int n, p;
    cin >> n >> p;
    while (n||p) {
        vector<ll>arr(n+5);
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        vector<ll> dp(p+5,0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= p; ++j) {
                if (j >= arr[i]) dp[j]+=dp[j-arr[i]];
            }
//            OI(AI(dp));
        }
        cout << dp[p] << endl;
        cin >> n >> p;
    }
    return 0;
}
