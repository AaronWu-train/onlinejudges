#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FF first
#define SS second
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

struct SegmentTree{
	int n;
	vector<int> arr;
	vector<int> pos;

	void init(int _n, vector<int>& _arr) {
		n = _n;
		arr.resize(2*n+5);
		pos.resize(2*n+5);
		for (int i = 0; i < n; ++i) {
			arr[i+n] = _arr[i]; 
			pos[i+n] = i;
		}		
		
		for (int i = n-1; i > 0; --i) {
			if (arr[2*i] <= arr[2*i+1]) {
				pos[i] = pos[2*i];
				arr[i] = arr[2*i];
			} else {
				pos[i] = pos[2*i+1];
				arr[i] = arr[2*i+1];	
			}
		}
	}
	
	void push(int i) {
		i >>= 1;
		while(i) {
			if (arr[2*i] <= arr[2*i+1]) {
				pos[i] = pos[2*i];
				arr[i] = arr[2*i];
			} else {
				pos[i] = pos[2*i+1];
				arr[i] = arr[2*i+1];	
			}
			i >>= 1;
		}
	}
	
	pair<int,int> query(int l, int r) {
		l += n; r += n;
		int ans = INT_MAX;
		int rpos = 0;
		while (l < r) {
			if (l & 1) {
				if (arr[l] < ans) {
					rpos=pos[l];
				   	ans = arr[l];
				} else if (arr[l] == ans) {
					rpos = min(rpos, pos[l]);
				}
				l++;
			}
			if (r & 1) {
				--r;
				if (arr[r] < ans) {
					rpos=pos[r];
				   	ans = arr[r];
				} else if (arr[r] == ans) {
					rpos = min(rpos, pos[r]);
				}
			}
			l >>= 1; r >>= 1;
		}	
		return {ans, rpos};
	}

	void modify(int i, int v) {
		arr[i+n] = v;
		push(i+n);
	}

};


signed main(){_
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n+1);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		SegmentTree st;
		st.init(n, arr);
		int l = -1, r = k;
		for (int i = 0; i < n - k + 1; ++i) {
			int ans, retpos;
			//do {
				++l;
				auto ttt = st.query(l, i + k);
				ans = ttt.FF; retpos = ttt.SS;
			//} while (0 && retpos == l && l+1 < i + k );

			//if (l >= i + k) continue;
			int temp = st.arr[l+n];
			st.modify(retpos, temp);	
			st.modify(l, ans);
		}
		for (int i = 0; i < n; ++i) {
			cout << st.arr[i+n] << " \n"[i == n-1];
		}
	}

	return 0;
}
