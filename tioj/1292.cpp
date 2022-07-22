#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
#define pb push_back
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
vector<bool>visited;
vector<int> deep;
vector<int> fa;
void dfs(int i, vector<int>adj[], int dep) {
    visited[i] = 1;
    deep[i] = dep;
    for (auto j : adj[i]) {
        if (!visited[j]) {
            fa[j] = i;
            dfs(j, adj, dep+1);
        }
    }
}



signed main() {_
    int n;
    cin >> n;
    int line = n - 1;
    vector<int>adj[n+5];
    vector<int>deg(n+5, 0);
    
    for (int i = 0; i < line; ++i) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    visited.resize(n+1,0);
    deep.resize(n+1,0);
    fa.resize(n+1,0);
    fa[1] = -1;
    vector<pair<int, int>> od;
    dfs(1, adj, 1);
    for (int i = 1; i <= n; ++i) od.pb({deep[i], i});
    sort(AI(od), greater<pair<int, int>>() );
    vector<bool>covered(n+1,0);
    set<int>s;
    for (int i = 0; i < n-1; ++i) {
        if (!covered[od[i].second]) {
            covered[fa[od[i].second]] = 1;
            covered[od[i].second] = 1;
            s.insert(fa[od[i].second]);
//            debug(od[i].second);
        }
    }
//    for(auto i : s)cerr << i << " ";cout<<endl;
    cout << s.size() << endl;
    
    
    return 0;
}
