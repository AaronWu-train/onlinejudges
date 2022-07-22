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
    cin >> n;
    vector<ll> wgh;
    vector<ll> mag;
    for (int i = 0; i < n; ++i) {
        ll w, m, c;
        cin >> w >> m >> c;
        int used = 0;
        for (int j = 0; (1<<j) <= c; ++j) {
            if (used + (1<<j) > c) break;
            used+=(1<<j);
            wgh.push_back(w * (1<<j));
            mag.push_back(m * (1<<j));
        }
        if (c - used) {
            wgh.push_back(w * (c - used));
            mag.push_back(m * (c - used));
        }
    }
    int T;
    cin >> T;
//    OI(AI(wgh));
//    OI(AI(mag));

    vector<ll>dp(T+5, 0);
    dp[0] = 0;
    for (int i = 0; i < mag.size(); ++i) {
        for (int j = T; j >= 0; --j) {
            if (j >= wgh[i]) dp[j] = max(dp[j], dp[j - wgh[i]] + mag[i]);
        }
    }
    cout << dp[T] << endl;
    
    return 0;
}
