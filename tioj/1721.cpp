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
    while (cin >> n) {
        vector<ll> arr(n);
        vector<ll> ans(n, 1);
        vector<pair<ll, ll>> sing;

        for (auto &i : arr) cin >> i;
        for (int i = 0; i < n; ++i) {
            while (!sing.empty() && sing.back().first < arr[i]) {
                ans[i]+=sing.back().second;
                sing.pop_back();
            }
            sing.push_back({arr[i], ans[i]});
            if (sing.size() > 1) ans[i]++;
        }
       
        sing.clear();
        vector<ll> ans2(n, 1);
        
        for (int i = n-1; i >= 0; --i) {
            while (!sing.empty() && sing.back().first < arr[i]) {
                ans2[i]+=sing.back().second;
                sing.pop_back();
            }
            sing.push_back({arr[i], ans2[i]});
            if (sing.size() > 1) ans2[i]++;
        }
        
        for (int i = 0; i < n; ++i) {
            cout << ans[i]+ans2[i]-1 << " \n"[i==n-1];
        }
    }
    return 0;
}
