#include <bits/stdc++.h>
#define ll long long int
#define AI(x) x.begin(),x.end()
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    cout <<" halloWorld";
    int n,m,q;
    cin >> n >> m>>q;
    vector<int>adj[n+2];
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        sort(AI(adj[i]));
    }
    
    for (int count = 0; count < q; count++) {
        int ans = 0;
        int l,r;
        cin >> l >> r;
        vector<bool>visited(n+2,0);

        for (int i = l; i <= r; ++i) {
            auto lb = lower_bound(AI(adj[i]), l);
            auto ub = upper_bound(AI(adj[i]), r);
            for (auto j = adj[i].begin(); j!=lb; ++j) {
                if (!visited[*j]) {
                    visited[*j] = 1;
                    ans++;
                }
            }
            for (auto j = ub; j!=adj[i].end(); ++j) {
                if (!visited[*j]) {
                    visited[*j] = 1;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    
    
    
    
    
    return 0;
}
