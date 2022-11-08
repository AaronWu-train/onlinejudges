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


int n, l;
string prev(string s) {
	int i = s.size()-1;
	while (i) {
		s[i]--;
		if (s[i] < '0') s[i] = '2';
		if (s[i] != '1') return s;
		s[i] = '0';
		i--;
	}	
	return s;
}
map <string, bool> used;

string next(string s) {
	int i = s.size()-1;
	while (i) {
		s[i]++;
		if (s[i] <= '2') return s;
		s[i] = '0';
		i--;
	}	
	return to_string(0)+s;
}

int cnt[3][15] = {0};
bool valid(string s) {
	if (used[s]) return 0;
	for (int i = 0; i < l; ++i) {
		if (cnt[ s[i] - '0' ][i] + 1 > n) return 0;
	}	
	return 1;
}


signed main(){_
	cin >> n >> l;
	vector<string> ans;
	string s;
	for (int i = 0; i < l; ++i) s += "0";
	s[0] = '2';
	for (int i = 0; i < n; ++i) {
		if (valid(s)) {
			for (int i = 0; i < l; ++i) {
				cnt[ s[i] - '0' ][i]++;
			}
			ans.pb(s);
			used[s] = 1;
		} else {
			i--;
		}
		s = next(s);
	}
	OI(AI(ans));
	debug(valid("00"));

	s = "";
	for (int i = 0; i < l; ++i) s += "2";
	s[0] = '0';

	for (int i = 0; i < n; ++i) {
		if (valid(s)) {
			for (int i = 0; i < l; ++i) {
				cnt[ s[i] - '0' ][i]++;
			}
			used[s] = 1;
			ans.pb(s);
		} else {
			i--;
		}
		s = prev(s);
	}


	s = "";
	for (int i = 0; i < l; ++i) s += "0";
	s[0] = '1';

	for (int i = 0; i < n; ++i) {
		if (valid(s)) {
			for (int i = 0; i < l; ++i) {
				cnt[ s[i] - '0' ][i]++;
			}
			ans.pb(s);
			used[s] = 1;
		} else {
			i--;
		}
		s = prev(s);
	}


	sort(AI(ans));
	for(auto i : ans) cout << i << endl;
	return 0;
}
