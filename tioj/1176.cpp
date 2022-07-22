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
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int>dp;
    vector<int>ans(n, 0);
    for (int i = n-1; i>=0; --i) {
        while (!dp.empty() && arr[dp.back()] < arr[i]) {
            dp.pop_back();
//            ans[i]++;
        }
        if(!dp.empty()) ans[i] = dp.back() - i;
        else ans[i] = n-1-i;
        
        dp.push_back(i);
    }
    for (auto i : ans) cout << i << endl;
    
    
    
    return 0;
}
