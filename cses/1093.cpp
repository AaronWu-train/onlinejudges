#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll    long long
#define pb    push_back
#define endl  '\n'
#define AI(x) begin(x), end(x)
#ifdef DEBUG
#define debug(args...) LKJ("\033[1;32m[ " + string(#args) + " ]\033[0m", args)
template <class I>
void LKJ(I&& x) {
    cerr << x << '\n';
}
template <class I, class... T>
void LKJ(I&& x, T&&... t) {
    cerr << x << ", ", LKJ(t...);
}
template <class I>
void OI(I a, I b) {
    while (a < b) cerr << *a << " \n"[next(a) == b], ++a;
}
#else
#define debug(...) 0
#define OI(...)    0
#endif
#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int ll

const ll mod = 1e9 + 7;
signed   main() {
    _ ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
        cout << 0 << endl;
    else {
        debug(10);
        vector<ll> dp(sum + 5, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= i) {
                    dp[j] = dp[j] + dp[j - i] % mod;
                }
                dp[j] %= mod;
            }
        }
        cout << (ll)dp[sum / 2] * 500000004 % mod << endl;
    }

    return 0;
}
