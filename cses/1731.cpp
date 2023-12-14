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
const int mod = 1e9+7;

struct Trienode {
	int cnt=0;
	vector<Trienode*> child;
	Trienode () {
		cnt = 0;
		child.resize(30);
	}


	void add(string s) {
		Trienode* now = this;
		for (auto &c : s) {
			if (!now->child[c-'a']) now->child[c-'a'] = new Trienode();
			now = now->child[c-'a'];
		}
		now->cnt++;
	}
};
signed main(){_
	Trienode* trie = new Trienode();
	int n, k;
	string s;
	cin >> s;
	n = s.size();
	cin >> k;
	for (int i = 0; i < k; ++i) {
		string l;
		cin >> l;
		trie->add(l);
	}
	vector<ll> dp(n+5);
	s = "#" + s;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		Trienode* now = trie;
		for (int j = i; j <= n; ++j) {
			if (!now->child[s[j]-'a']) break;
			now = now->child[s[j]-'a'];
			dp[j] += dp[i-1] * now->cnt % mod;
			dp[j] %= mod;	
			debug(i, j, dp[j]);
		}	
	}
	cout << dp[n] % mod << endl;

	return 0;
}
