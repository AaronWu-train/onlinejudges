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

signed main(){_
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<int> cnt(256,0);
		int mult = 1;		
		bool head = 1;
		bool front = 1;

		for (int i = 0; i < s.size(); ++i) {
			if (head) {
				if (s[i] >= '0' && s[i] <= '9'){
					mult = s[i] - '0';
					head = 0; 
					continue;
				}
				head = 0;
			}
			if (s[i] == '+') {
				head = 1;
				mult = 1;
				continue;
			}
			if (s[i] == '-' || s[i] == '>') {
				front = 0;
				head = 1;
				mult = 1;
				continue;
			}
			int ab = (front) ? 1 : -1;
			if (s[i] >= '0' && s[i] <= '9') {
				cnt[s[i-1]] += mult * ab * (s[i] - '0' - 1);
				continue;
			}
			cnt[s[i]] += mult * ab;
		}
		
		int flag = 1;
		for (auto i : cnt) {
			if (i != 0) {
				cout << "NE" << endl;
				flag = 0;
				break;
			}
		}
		if(flag) cout << "DA" << endl;

	}	

	return 0;
}
