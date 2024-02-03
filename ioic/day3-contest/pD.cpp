#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
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
#define int long long
#define pii pair<int, int>
const int xxn = 3e5+5;
vector<pii> g[xxn];
bool vis[xxn];
int cur[xxn];
vector<pii> ans;

void dfs(int v) {
	for(; cur[v] < g[v].size(); cur[v]++) {
		int i = cur[v];
		int u = g[v][i].first;
		int id = g[v][i].second;
		if(vis[id]) continue;
		vis[id]=1;
		dfs(u);
		ans.pb({v, u});
	}
}

signed main(){_
	int n, m;
	cin >> n >> m;
	vector<int> in(n+5);
	vector<int> out(n+5);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		out[a]++;	
		g[a].pb({b,i});
	}
	for (int i = 1; i <=n ; ++i) {
		sort(AI(g[i]), greater<pii>());
	}
	int fg = 0;
	int ha = 0;
	for (int i = 2; i < n; ++i) {
		if (in[i] != out[i]) {
			fg = 2;
		}
		if (out[i] >= 3) ha = 1;	
	}
	if (out[1] >= 3 || out[n] >= 2) ha = 1;
	if (out[1] - in[1] != 1 || in[n] - out[n] != 1) {
		fg = 2;
	}

	dfs(1);
	if(fg == 2 || ans.size() < n) {
		cout << 0 << endl;
		return 0;
	}	
	cout <<  ha+1 << endl;
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}	
	return 0;
}
