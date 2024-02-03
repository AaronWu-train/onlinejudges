#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#if __has_include ("reporter.h")
#   include "reporter.h"
#else
#   include "lib0058.h"
#endif 

std::vector<int> get_ranking(int N) {
	using namespace std;
	int n = N;
	vector<int> ans(n, 1);
	for (int i = 0; i < n; ++i) {
		ans[i] = i;
	}
	random_shuffle(AI(ans), random_device());
	for (int i = 0; i < n; ++i) {
		int mx = 0, mxid = n-1;
		for (int j = n-1; j > i+1; --j) {
			auto tmp = ans;
			swap(tmp[i+1], tmp[j]);
			auto f = get_downvote(tmp);
			if (f > mx) {
				mx = f;
				mxid = n-1;
			}
			swap(ans[i], ans[mxid]);
		}		
	}	
    return ans;
}
