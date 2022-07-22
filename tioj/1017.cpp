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
        vector<int>arr(n);
        vector<int>re(n);
        vector<int>le(n);
        for (auto &i : arr) cin >> i;
        le[0] = arr[0];
        for (int i = 1; i < n; ++i){
            le[i] = max(le[i-1],arr[i]);
        }
        re[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; --i) {
            re[i] = min(re[i+1], arr[i]);
        }
        int ans = 0;
        for (int i = 1; i < n-1; ++i) {
            if (arr[i] > le[i-1] && arr[i] < re[i+1]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
