#include <bits/stdc++.h>
using namespace std; 

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	bool not_prime[20000] = {1, 1, 0};
	for (int i = 2; i <= n; ++i) {
		if (!not_prime[i]) {
			for (int j = i*i; j <= n; j += i) {
				not_prime[j] = true;
			} 
		}
	}	

	stringstream s;
	int p = 0;

	for (int i = 1; i <=n; ++i) {
		if (n % i == 0) {
			if (k == 2 && not_prime[i]) continue;
			s << i << " ";
			p++;
		}
	}

	int f;
	while (s >> f) {
		cout << f;
		if (--p) cout << ",";
	}
}
