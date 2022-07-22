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

void dfs(int i, vector<bool>& visited, vector<int>& deep, vector<int>adj[]) {
    visited[i] = 1;
//    debug(i);
    for (auto j : adj[i]) {
        if (!visited[j]) {
            deep[j] = deep[i] + 1;
            dfs(j, visited, deep, adj);
        }
    }
}

signed main() {_
    int n;
    cin >> n;
    vector<int>adj[n];
    
    for (int i = 0; i < n; ++i) {
        int k;
        while (cin >> k && k != -1) {
            adj[i].push_back(k);
            adj[k].push_back(i);
        }
    }
//    for (auto &i : adj) OI(AI(i));
    vector<int>deep(n,0);
    vector<int>deep2(n,0);
    vector<bool>visited(n, 0);
    vector<bool>visited2(n, 0);
    dfs(0, visited, deep, adj);
//    OI(AI(deep));
    int maxdep = 0, id = 0;
    for (int i = 1; i < n; ++i) {
        if (deep[i] > maxdep){
            id = i;
            maxdep = deep[i];
        }
    }
    deep2[id] = 0;
    dfs(id, visited2, deep2, adj);
    for (auto i : deep2) maxdep = max(maxdep, i);
    cout << maxdep << endl;
    
    return 0;
}
