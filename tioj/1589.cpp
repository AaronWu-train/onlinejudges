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
    int v,e,m;
    cin >> v >> e >> m;
    vector<int>adj[v+5];
    vector<int>incount(v+5,0);
    vector<ll>dp(v+5,0);
    vector<int>order;
    for (int i = 0; i < e; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        incount[b]++;
    }
    for (int i = 0; i < v; ++i) {
        if (incount[i]==0) order.push_back(i);
    }
    OI(AI(order));
    for (int i = 0; i < v; ++i) {
        for (auto &j : adj[order[i]]) {
            incount[j]--;
            if (!incount[j]) order.push_back(j);
        }
    }
    OI(AI(order));
    int s,t;
    cin >> s >> t;
    dp[s] = 1;
    for (auto &i : order) {
        for (auto &j : adj[i]) {
            dp[j] = (dp[j] + dp[i]) % m;
        }
    }
    cout << dp[t] << endl;
    return 0;
}
