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
    vector<ll>ans(10005, 0);
    ans[0] = 1;
    vector<ll>dp(20005, 0);
    dp[0] = 1;
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 1; j <= 2*i; ++j) {
            dp[j] = (dp[j] + dp[j-1]) % 10000;
        }
        ans[i] = dp[2*i];
    }
    
    OI(ans.begin(), ans.begin()+25);
    int n;
    cin >> n;
    while (n) {
        if(n >= 8){
            putchar_unlocked(ans[n] % 10000 / 1000 + '0');
            putchar_unlocked(ans[n] % 1000 / 100 + '0');
            putchar_unlocked(ans[n] % 100 / 10 + '0');
            putchar_unlocked(ans[n] % 10 + '0');
        }
        else{
            if(ans[n] >= 1000) putchar_unlocked(ans[n] % 10000 / 1000 + '0');
            if(ans[n] >= 100) putchar_unlocked(ans[n] % 1000 / 100 + '0');
            if(ans[n] >= 10) putchar_unlocked(ans[n] % 100 / 10 + '0');
            putchar_unlocked(ans[n] % 10 + '0');
        }
        putchar_unlocked('\n');
        cin >> n;
    }
    return 0;
}

