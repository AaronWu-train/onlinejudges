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

const int maxn = 2e5+5;
vector<int> adj[maxn];
vector<int> terrible;
int n;

int dfs(int i, vector<bool>&visited) {
	visited[i] = 1;
	int mysize = 1;
	for (auto c : adj[i]) {
		if (!visited[c]) {
			int k = dfs(c, visited);
			terrible[i] = max(terrible[i], k);
			mysize += k;
		}
	}
	int fatherTreeSize = n - mysize;
   	terrible[i]= max(fatherTreeSize, terrible[i]);
	return mysize;
}

int main(){_
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	terrible.resize(n+5, 0);
	vector<bool>visited(n+5,0);
	dfs(1, visited);
	for (int i = 1; i <= n; ++i) {
		if (terrible[i] <= n/2) {
			cout << i << endl;
			break;
		}
	}	


	return 0;
}
