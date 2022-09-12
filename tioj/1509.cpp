#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
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
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){_
	int n, m;
	cin >> m >> n;
    vector <pair<int, int>> adj[n+5];
    vector <pair<int, int>> adj2[n+5];
	for (int i = 0; i < n; ++i) {
		int p, q, w;
		cin >> p >> q >> w;
        adj[p].push_back({q,w});
        adj2[q].push_back({p,w});
	}
    vector<bool> visited(m+5, 0);
    vector<bool> fa(m+5, 0);
	vector<ll> dis(m+5, 2e9);
	dis[1] = 0;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	pq.push({0, {1, 0}});
	while(!pq.empty()) {
		auto cur = pq.top();
        pq.pop();

		if (visited[cur.second.first]) continue;
//        debug(cur.first, cur.second.first, cur.second.second, fa[cur.second.second]);

		visited[cur.second.first] = 1;
		fa[cur.second.second] = 1;
		for (auto [e, w] : adj[cur.second.first]) {
			if (e != 1 && dis[cur.second.first] + w < dis[e]) {
				dis[e] = dis[cur.second.first] + w;
				pq.push({dis[e], {e, cur.second.first}});
			}
		}
	}
	
    vector<bool> visited2(m+5, 0);
    vector<ll> dis2(m+5, 2e9);
    dis2[1] = 0;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq2;
    pq2.push({0, {1, 0}});
    while(!pq2.empty()) {
        auto cur = pq2.top();
        pq2.pop();
        if (visited2[cur.second.first]) continue;
        visited2[cur.second.first] = 1;
        for (auto [e, w] : adj2[cur.second.first]) {
            if (e != 1 && dis2[cur.second.first] + w < dis2[e]) {
                dis2[e] = dis2[cur.second.first] + w;
                pq2.push({dis2[e], {e, cur.second.first}});
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += dis[i] + dis2[i];
    }
    cout << ans << endl;
	return 0;
}
