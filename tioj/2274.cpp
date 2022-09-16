#include <bits/stdc++.h>
using namespace std;
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

struct s{
	int l, r, u, d;
};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	ll ans = -LLONG_MIN;
	s temp = {0, 0, 0, 0};
	for (int i = 0; i < n; ++i) {
		ll best = arr[i][0];
		s cur = {0,0,i,i};
		for (int j = 1; j < m; ++j) {
			if(best + arr[i][j] >= arr[i][j]) {
				cur.r=j;
				best = best + arr[i][j];
			}
			else{
				best = arr[i][j];
				cur = {j,j,i,i};
			}
			if (best > ans) {
					ans = best;
					temp = cur;
			}
			
		}
	}
	for (int i = 0; i < m; ++i) {
		ll best = arr[0][i];
		s cur = {i,i,0,0};
		for (int j = 1; j < n; ++j) {
			if(best + arr[j][i] >= arr[j][i]) {
				cur.d=j;
				best = best + arr[j][i];
				
			} else {
				best = arr[j][i];
				cur = {i,i,j,j};
			}
			if (best > ans) {
					ans = best;
					temp = cur;
			}
			debug(best, ans, i, j);
			debug(temp.l, temp.r, temp.u, temp.d);

		}
	}
	cout << ans << endl;
	debug(temp.l, temp.r, temp.u, temp.d);
	for (int i = 0; i < temp.l; ++i) {
		cout << 'L';
	}
	for (int i = 0; i < m-temp.r-1; ++i) {
		cout << 'R';
	}
	for (int i = 0; i < temp.u; ++i) {
		cout << 'U';
	}
	for (int i = 0; i < n-temp.d-1; ++i) {
		cout << 'D';
	}
	if (temp.l==temp.r){
		cout << 'L' << endl;
	}else{
		cout << 'D' << endl;
	}
	
	return 0;
}



