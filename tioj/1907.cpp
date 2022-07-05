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
const int maxm = 20005;
const int maxh = 1005;

struct BIT{
    ll arr[maxm] = {0};
    void modify(ll i, ll x) {
        for (i;i<=maxh;i+=(i&-i)){
            arr[i] = max(arr[i],x);
        }
    }
    ll query(ll i) {
        ll ans = 0;
        for (i; i>0; i-=(i&-i)){
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<pair<int, int>> arr(m);
        for (auto &i : arr) cin >> i.first >> i.second;
        sort(AI(arr),[](auto &a, auto &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        BIT bit;
        for (auto &i : arr) {
            bit.modify(i.second, bit.query(i.second-1)+1);
        }
        cout << bit.query(1001) << endl;
    }
    
    
    
    return 0;
}
