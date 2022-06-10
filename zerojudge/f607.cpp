#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii;
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l;
    cin >> n >> l;
    set<int>dp;
    ll ans = 0;
    vector<pii>arr;
    for(int i = 0; i < n; ++i) {
        int x,j;
        cin >> x >> j;
        arr.push_back({j,x});
    }
    sort(AI(arr));
    for(auto i : arr) {
        auto it =dp.lower_bound(i.second);
        int low, high;
        if(it == dp.begin())low = 0;
        else low = *prev(it);
        if(it == dp.end())high = l;
        else high = *it;
        ans += high-low;
        dp.insert(i.second);
    }

    cout << ans <<endl;

	return 0;
}
