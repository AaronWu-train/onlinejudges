#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#define pii pair<int, int>
#define PB push_back
#define FF first
#define SS second
#ifdef AaW
#define debug(args...) LKJ("[" #args "]",args)
template<class I> void LKJ(I&&x) {cerr << x << endl;}
template<class I, class ...T> void LKJ(I&&x, T&&...t) {cerr << x << " ", LKJ(t...);}
template<class I> void OI(I a, I b){while (a != b) cerr << *a << " \n"[next(a)==b], a++;}
#else 
#define debug(...) 0
#define OI(...) 0
#endif


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k;
	cin >> n >> k;
	string peach;
	cin >> peach;
	for (auto &i : peach) i-='0';
	vector<int>arr(n);
	for (auto &i : arr) cin >> i;
	
	vector<int> pre(n);
	vector<int> prek(n);
	pre[0] = arr[0];
	prek[0] = peach[0];
	for (int i = 1; i < n; ++i) {
		pre[i] = arr[i]+pre[i-1];
		prek[i] = peach[i] + prek[i-1];
	}

	deque<int> mono;
	ll ans = 0;
	ll cursum = 0, curk = 0;
	for (int i = 0; i < n; ++i) {
		while(!mono.empty() && prek[i]-prek[mono.front()] >1+k) mono.pop_front();
		cursum = 0;
		if (mono.empty()) {
			cursum = arr[i]; 
		} else {
			cursum = pre[i]- pre[mono.front()];
		}
		ans = max(ans, cursum);

		while (!mono.empty() && pre[i] >= pre[mono.back()]) {
			mono.pop_back();
		}
		mono.push_back(i);
	}
	cout << ans << endl;
	
	
	return 0;
}



