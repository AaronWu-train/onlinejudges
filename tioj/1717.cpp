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
        vector<int>child[n+5];
        vector<int>indeg(n+5, 0);
        vector<int>lag(n+5);
        for (int i = 1; i <= n; ++i) {
            cin >> lag[i];
            int k;
            cin >> k;
            while (k--) {
                int temp;
                cin >> temp;
                indeg[temp]++;
                child[i].push_back(temp);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] == 0) {
                bfs.push({lag[i], i});
            }
        }
        int ans = 0;
        while (!bfs.empty()) {
            auto [time, i] = bfs.top();
            ans = max(ans, time);
            bfs.pop();
            for (auto &j : child[i]) {
                indeg[j]--;
                if (indeg[j] == 0) {
                    bfs.push({time+lag[j], j});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
