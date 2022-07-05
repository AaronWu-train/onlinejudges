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
const int maxn = 1e7+5;
ll mcount[maxn] = {0};
ll sum[maxn] = {0};

signed main() {_
    int t;
    cin >> t;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j*i < maxn; ++j) {
            mcount[i*j]++;
            sum[i*j]+=i;
        }
    }
    
    while (t--) {
        int k;
        cin >> k;
        cout << mcount[k] * sum[k] << endl;
    }
    
    
    return 0;
}
