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
int n, m;
const int maxn = 1e4+5;
vector<int>adj[maxn];
vector<int>ans;
void dfs(int i, int fa, vector<bool>& visited, vector<int> &dep, vector<int>& low) {
    visited[i] = 1;
    dep[i] = low[i] = dep[fa]+1;
    int c = 0;
    bool isKnee = false;
    for (auto j : adj[i]) {
        if (j != fa) {
            if (visited[j]) {
                low[i] = min(dep[j], low[i]);
            }
            else {
                c++;
                dfs(j, i, visited, dep, low);
                low[i] = min(low[i], low[j]);
                if (fa && low[j] >= dep[i]) isKnee = 1;
            }
        }
    }
    if ((!fa && c > 1) || isKnee) ans.push_back(i);
}

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans.clear();
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>visited(n+5,0);
        vector<int>dep(n+5, 0);
        vector<int>low(n+5, 0);
        dfs(1, 0, visited, dep, low);
        sort(AI(ans));
        cout << ans.size() << endl;
        if (ans.empty()) cout << 0 << endl;
        else {
            for (auto i : ans) {
            cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
