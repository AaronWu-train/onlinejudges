#pragma GCC optimize("Ofast")
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
    int n;
    cin >> n;
    vector<ll>arr(n);
    for (auto &i : arr) cin >> i;
    vector<int>ans(n,0);
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            ans[i]=-1;
        }
        else if (arr[i] == 0) {
            if (i>0 && ans[i-1]>0) {
                ans[i]=1;
            }
        }
        if (arr[i] >= 1) ans[i] = 1;
    }
    for (int i = n-1; i >=0; i--) {
         if (arr[i] == 0) {
            if (i<n-1 && ans[i+1]>0) {
                ans[i]=1;
            }
        }
    }
    int ret = 0;
    for (auto i : ans) {
        ret+=i;
    }
    cout << ret << endl;
    return 0;
}
