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
const int maxm = 1e6+5;
const int mod = 1000000009;

vector<ll>sortedH;
inline ll getid(ll x){
    return lower_bound(AI(sortedH), x) - sortedH.begin();
}

struct BIT{
    ll arr[maxm] = {0};
    void modify(ll i, ll x) {
        i = getid(i)+1;
        for (;i<=maxm;i+=(i&-i)){
            arr[i] = (arr[i] + x) % mod;
        }
    }
    ll query(ll i) {
        ll ans = 0;
        i = getid(i)+1;
        for (; i>0; i-=(i&-i)){
            ans = (ans + arr[i])%mod;
        }
        return ans%mod;
    }
};


signed main() {_
    int n;
    cin >> n;
    vector<pair<ll, ll>>arr;
    for (int i = 0; i < n; ++i) {
        ll w,h;
        cin >> w >> h;
        sortedH.push_back(h);
        arr.push_back({w,h});
    }
    sort(AI(sortedH));
    sortedH.erase(unique(AI(sortedH)), sortedH.end());
    sort(AI(arr),[](auto &a, auto &b){
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    ll ans = 0;
    BIT sum;
    BIT count;
    for (auto &i : arr) {
        ans = ((ans + count.query(i.second)*i.first%mod*i.second%mod)%mod - sum.query(i.second) + mod) %mod;
        count.modify(i.second, 1);
        sum.modify(i.second, i.first%mod*i.second%mod);
    }
    cout << ans%mod << endl;
    
    return 0;
}
