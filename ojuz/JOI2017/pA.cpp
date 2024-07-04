#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define AI(x) begin(x),end(x)
#define endl '\n'

struct BIT{
	vector<long long> arr;
	int n;
	void init(int _n) {
		n = _n;
		arr.resize(n+5);
	}

	long long query(int i) {
		long long sum = 0;
		for (i; i > 0; i -= (i&-i)) {
			sum += arr[i];
		}
		return sum;
	}

	void modify(int i, long long v) {
		for (i; i <= n; i += (i&-i)) {
			arr[i] += v;
		}
	}

};


signed main() {
	long long n, q, s, t;
	cin >> n >> q >> s >> t;
	s = -s;
	t = -t;
	vector<long long> arr(n+1);
	for (auto &i : arr) cin >> i;
	vector<long long> diff(n+1);
	for (int i = 1; i <= n; ++i) {
		if (arr[i] > arr[i-1]) {
			diff[i] = s * (arr[i] - arr[i-1]);
		}
		else {
			diff[i] = t * (arr[i] - arr[i-1]);
		}
	}

	BIT bit, h;
	bit.init(n+1);
	h.init(n+1);

	for (int i = 1; i <= n; ++i) {
		bit.modify(i, diff[i]);
		h.modify(i, arr[i] - arr[i-1]);
	}

	// for (int i = 0; i <= n; ++i) cerr << h.query(i) << " "; cerr << endl;
	// for (int i = 0; i <= n; ++i) cerr << bit.query(i) << " "; cerr << endl;


	while(q--) {
	    long long l, r, x;
	    cin >> l >> r >> x;
	    long long ll = bit.query(l) - bit.query(l-1);
	    long long rr = bit.query(r+1) - bit.query(r);

	    long long lh = h.query(l) - h.query(l-1);
	    long long lhn = lh + x;
	    if (lhn > 0) bit.modify(l, lhn*s - ll);
	    else bit.modify(l, lhn*t - ll);

	   	long long rh = h.query(r+1) - h.query(r);
	   	long long rhn = rh - x;
	   	if (rhn > 0) bit.modify(r+1, rhn*s - rr);
	    else bit.modify(r+1, rhn*t - rr);

	    h.modify(l, x);
	    h.modify(r+1, -x);


		// cerr << "H: "; for (int i = 0; i <= n; ++i) cerr << h.query(i) << " "; cerr << endl;
		// cerr << "T: "; for (int i = 0; i <= n; ++i) cerr << bit.query(i) << " "; cerr << endl;

	    cout << bit.query(n) << endl;

	}	


}
