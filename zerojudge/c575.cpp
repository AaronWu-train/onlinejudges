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
int arr[50005];
int n, k;

bool is_legal(int r){
  int cover = 0; // 最右側覆蓋位置
  int stand = 0; // 用了幾個基地台
  for(int i=0; i<n; i++){
    if(arr[i] > cover){
      cover = arr[i] + r;			
      stand++;
    }
  } 
  if(stand > k) return false; // 基地台數量不符合
  else return true;
}

signed main(){_
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int l = 0, r = 1e9+5;
	while (l < r) {   // 左閉右閉 維護1區間
		int mid = l + (r - l) / 2;
		if (is_legal(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;

	return 0;
}
