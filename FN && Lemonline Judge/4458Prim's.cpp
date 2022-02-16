#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct E{
    int v,w;
};
struct cmp{
    bool operator()(E a,E b){
        return a.w>b.w;
    }
};

int main() {_
    int n,m;
    cin >> n >> m;
    vector<E>Q[n+3];
    bool vis[n+3];
    int dis[n+3];
    fill(dis,dis+n+3,INT_MAX);
    fill(vis,vis+n+3,0);
    int u,v,w;
    for(int i=0;i<m;++i){
        cin >> u >> v >> w;
        Q[u].push_back({v,w});
        Q[v].push_back({u,w});
    }
    
    priority_queue<E,vector<E>,cmp> pq;
    pq.push({1,0});
    ll ans = 0;
    dis[1]=0;
    
    while (!pq.empty()) {
        E cur = pq.top();
        pq.pop();
        if (vis[cur.v])continue;
        vis[cur.v]=1;
        ans += cur.w;
        for (auto [v,w]:Q[cur.v]) {
            if (!vis[v] && dis[v]>w) {
                dis[v]=w;
                pq.push({v,w});
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
