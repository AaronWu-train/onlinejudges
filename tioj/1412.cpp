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
ll n, k, m;

bool check(ll x, vector<ll>&arr, vector<ll>&need) {
    ll temp = 0;
    for (int i = 0; i < n; ++i) {
        if (need[i] > arr[i]*x) return 0;
        else {
            temp += arr[i]*x - need[i];
        }
    }
    return (temp >= (k*m));
}


signed main() {_
    while (cin >> n) {
        vector<ll>arr(n, 0);
        for (auto &i : arr) cin >> i;
        cin >> k;
        vector<ll> need(n, 0);
        for (auto &i : need) cin >> i;
        cin >> m;
//        OI(AI(arr));
//        OI(AI(need));
        ll l = 0, r = 1e6;
        while (l < r - 1) {
            ll mid = (l + r)/2;
//            debug(mid);
            if (check(mid, arr, need)) r = mid;
            else l = mid;
        }
        cout << r << endl;
        
    }
    return 0;
}
