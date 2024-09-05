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
	vector<int> arr(3), brr(3);
	string a, b; cin >> a;
	arr[2] = (a[0]-'0')*10+a[1]-'0';
	arr[1] = (a[3]-'0')*10+a[4]-'0';
	arr[0] = (a[6]-'0')*10+a[7]-'0';
	cin >> a;
	brr[2] = (a[0]-'0')*10+a[1]-'0';
	brr[1] = (a[3]-'0')*10+a[4]-'0';
	brr[0] = (a[6]-'0')*10+a[7]-'0';

	sort(AI(brr));
	do {
		brr[0] += 18;
		debug(brr[0], brr[1], brr[2]);
		debug(arr[0], arr[1], arr[2]);
		if (((brr[0] < arr[0]) || (brr[0] == arr[0] && (brr[1] < arr[1] || (brr[1] == arr[1] && brr[2] <= arr[2]))))
				&& brr[1] <= 12 && brr[2] <= 31) {

			if((brr[1] == 4 || brr[1] == 6 || brr[1] == 9 || brr[1] == 11) && brr[2] == 31) {
				brr[0] -= 18;
				continue;
			}	
			if ((brr[0]-18) % 4 != 0 && brr[1] == 2 && brr[2] >= 29) {brr[0] -= 18;continue;}
			if ((brr[0]-18) % 4 == 0 && brr[1] == 2 && brr[2] == 30) {brr[0] -= 18;continue;}

			cout << "YES" << endl;
			return 0;
		}
		brr[0] -= 18;
	} while (std::next_permutation(AI(brr)));
	cout << "NO" << endl;

	return 0;
}
