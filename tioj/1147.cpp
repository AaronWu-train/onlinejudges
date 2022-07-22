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

inline bool chmin(ll &a, ll b) {
    return (a > b)?(a = b, true):false;
}

signed main() {_
    int n;
    cin >> n;
    vector<pair<ll, ll>>arr;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(AI(arr));
    ll minn = INT_MAX;
    pair<ll, ll> minpair = {0, 0};
    for (auto [x, y] : arr) {
        ll sum = 0;
        for (auto& [nx, ny] : arr) {
            sum += abs(nx-x);
            sum += abs(ny-y);
        }
        if (chmin(minn, sum))minpair = {x, y};
    }
    cout << minpair.first << " " << minpair.second << endl;
    cout << minn << endl;
    
    return 0;
}
