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
    int m, n;
    cin >> m >> n;
    vector<vector<int>>high;
    vector<int>temp(n,0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int k;
            cin >> k;
            if (k) temp[j]++;
            else temp[j] = 0;
        }
        high.push_back(temp);
        OI(AI(temp));
    }
    int ans = 0;
    vector<pair<int, int>> single;
    for (int i = 0; i < m; ++i) {
        single.clear();
        single.push_back({0,-1});
        for (int j = 0; j < n; ++j) {
            while (!single.empty() && single.back().first >= high[i][j]) {
                single.pop_back();
            }
            if (high[i][j]) {
//                debug(single.back().first, single.back().second);
                ans = max(ans, high[i][j] * (j-single.back().second));
            }
            single.push_back({high[i][j], j});
        }
    }
    cout << ans << endl;
    return 0;
}
