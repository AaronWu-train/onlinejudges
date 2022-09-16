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


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int arr[7] = {1,6,6,6,6,6,6};
	for (int i = 0; i < 6; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int temp;
			cin >> temp;
			arr[temp]--;
		}
	}
	ll ans = 1;
	for (int i = 1; i <= 6; ++i) {
		ans *= arr[i];
	}
	cout << ans << endl;
	
	
	return 0;
}



