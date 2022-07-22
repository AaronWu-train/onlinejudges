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
    while(t--) {
        int n,x;
        cin >> n >> x;
        vector<int>arr(2*n,0);
        for (auto &i : arr) cin >> i;
        sort(AI(arr));
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            if (arr[i+n]-arr[i] < x )flag = 0;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
